/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:08:03 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/17 19:34:26 by cwoon            ###   ########.fr       */
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
		"Bad arguments, should be:  ./pipex file1 cmd1 cmd2 file2", \
		STDERR_FILENO);
	if (pipe(pipe_fd) == -1)
		error_handler(EXIT_FAILURE, strerror(errno), STDERR_FILENO);
	pid = fork();
	if (pid == -1)
		error_handler(EXIT_FAILURE, strerror(errno), STDERR_FILENO);
	if (pid == 0)
	{
		child_process(av, pipe_fd, envp);
        ft_printf("Child process (PID %d)\n", getpid());
	}
	else
	{
		waitpid(pid, NULL, 0);
		parent_process(av, pipe_fd, envp);
		ft_printf("Parent process is           %d\n", pid);
	}
}

void	child_process(char **av, int *pipe_fd, char **envp)
{
	int	infile_fd;

	infile_fd = open_file(av[1], STDIN_FILENO);
	if (!infile_fd && envp)
		error_handler(EXIT_FAILURE, "Open process unexpected", STDERR_FILENO);
	if (dup2(infile_fd, STDIN_FILENO) == -1 \
	|| dup2(pipe_fd[1], STDOUT_FILENO) == -1 \
	|| close(pipe_fd[0]) == -1)
		error_handler(EXIT_FAILURE, strerror(errno), STDERR_FILENO);
}

void	parent_process(char **av, int *pipe_fd, char **envp)
{
	int	outfile_fd;

	if ((dup2(pipe_fd[0], STDIN_FILENO) == -1))
		error_handler(EXIT_FAILURE, strerror(errno), STDERR_FILENO);
	outfile_fd = open_file(av[4], STDOUT_FILENO);
	if (!outfile_fd && envp)
		error_handler(EXIT_FAILURE, "Open process unexpected", STDERR_FILENO);
	if ((dup2(outfile_fd, STDOUT_FILENO) == -1 \
	|| close(pipe_fd[1]) == -1))
		error_handler(EXIT_FAILURE, strerror(errno), STDERR_FILENO);
}

void	execute_cmd(char *cmd, char **envp)
{

}
