/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:08:03 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/17 20:38:58 by cwoon            ###   ########.fr       */
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
		"Args Error: Should be:  ./pipex file1 cmd1 cmd2 file2", \
		STDERR_FILENO);
	if (pipe(pipe_fd) == -1)
		error_handler(-1, "Pipe Error", 2);
	pid = fork();
	if (pid == -1)
		error_handler(-1, "Fork Error", 2);
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
		error_handler(EXIT_FAILURE, "Undefined Open", STDERR_FILENO);
	if (dup2(infile_fd, STDIN_FILENO) == -1 \
	|| dup2(pipe_fd[1], STDOUT_FILENO) == -1 \
	|| close(pipe_fd[0]) == -1)
		error_handler(-1, "Child Dup2/Close Error", 2);
}

void	parent_process(char **av, int *pipe_fd, char **envp)
{
	int	outfile_fd;

	if ((dup2(pipe_fd[0], STDIN_FILENO) == -1))
		error_handler(-1, "Parent Dup2 STDIN Error", 2);
	outfile_fd = open_file(av[4], STDOUT_FILENO);
	if (!outfile_fd && envp)
		error_handler(EXIT_FAILURE, "Undefined Open", STDERR_FILENO);
	if ((dup2(outfile_fd, STDOUT_FILENO) == -1 \
	|| close(pipe_fd[1]) == -1))
		error_handler(-1, "Parent Dup2/Close Error", 2);
}

void	execute_cmd(char *av_cmd, char **envp)
{
	char	**str_cmd;
	char	*path;

	str_cmd = ft_split(av_cmd, ' ');
	path = get_path(str_cmd[0], envp);
	if(execve(path, str_cmd, envp) == -1)
	{
		ft_free_2d_array(str_cmd);
		error_handler(-1, "Execute Error", 2);
	}
}
