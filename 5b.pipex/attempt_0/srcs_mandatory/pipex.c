/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:08:03 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/18 20:03:45 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **av, int *pipe_fd, char **envp);
void	parent_process(char **av, int *pipe_fd, char **envp);

int	main(int ac, char **av, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (ac != 5)
		error_handler(EXIT_FAILURE, \
		"Args Error: Should be:  ./pipex <file1> <cmd1> <cmd2> <file2>", \
		STDERR_FILENO);
	else
	{
		if (pipe(pipe_fd) == -1)
			error_handler(-1, "Pipe Error", 2);
		pid = fork();
		if (pid == -1)
			error_handler(-1, "Fork Error", 2);
		if (pid == 0)
		{
			// printf("Child\n");
			child_process(av, pipe_fd, envp);
		}
		waitpid(pid, NULL, 0);
		// printf("Parent\n");
		parent_process(av, pipe_fd, envp);
	}
	exit(EXIT_SUCCESS);
}

void	child_process(char **av, int *pipe_fd, char **envp)
{
	int	infile_fd;

	infile_fd = open(av[1], O_RDONLY, 0777);
	if (infile_fd == -1)
		error_handler(-1, "File Opening Error", 2);
	if (dup2(infile_fd, STDIN_FILENO) == -1 \
	|| dup2(pipe_fd[1], STDOUT_FILENO) == -1 \
	|| close(pipe_fd[0]) == -1)
		error_handler(-1, "Child Dup2/Close Error", 2);
	execute_cmd(av[2], envp);
	// exit(EXIT_SUCCESS);
}

void	parent_process(char **av, int *pipe_fd, char **envp)
{
	int	outfile_fd;

	outfile_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile_fd == -1)
		error_handler(-1, "File Opening Error", 2);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1 \
	|| dup2(outfile_fd, STDOUT_FILENO) == -1 \
	|| close(pipe_fd[1]) == -1)
		error_handler(-1, "Parent Dup2/Close Error", 2);
	execute_cmd(av[3], envp);
	// exit(EXIT_SUCCESS);
}
