/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleow <bleow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:00:26 by bleow             #+#    #+#             */
/*   Updated: 2024/10/28 22:18:26 by bleow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int		fileopen(char **argv, t_pipex *pipex);
pid_t	make_fork(t_pipex *pipex);
void	child(char **argv, int *pipe_fd, char **envp, t_pipex *pipex);
void	parent(char **argv, char **envp, t_pipex *pipex);

/*
Function to open the file for writing.
*/
int	fileopen(char **argv, t_pipex *pipex)
{
	int	file;

	if (access(argv[pipex->args - 1], F_OK) == -1)
		file = open(argv[pipex->args - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		file = open(argv[pipex->args - 1], O_WRONLY | O_APPEND, 0777);
	if (file == -1)
		errormsg("openerr");
	return (file);
}

/*
Function for creating a new fork process.
*/
pid_t	make_fork(t_pipex *pipex)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		errormsg("forkerr");
		return (-1);
	}
	else if (pid > 0)
	{
		pipex->pid_created++;
		pipex->pids[pipex->pid_created - 1] = pid;
		return (pid);
	}
	else
		return (pid);
}

/*
Function to execute the child process.
*/
void	child(char **argv, int *pipe_fd, char **envp, t_pipex *pipex)
{
	int	infile;

	infile = 0;
	if (close(pipe_fd[0]) == -1)
		perror("close pipe_fd[0] in child failed");
	if (access(argv[1], F_OK | R_OK) == 0)
		infile = open(argv[1], O_RDONLY);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		perror("dup2 pipe_fd[1] to STDOUT_FILENO in child failed");
	if (close(pipe_fd[1]) == -1)
		perror("close pipe_fd[1] in child failed");
	if (dup2(infile, STDIN_FILENO) == -1)
		perror("dup2 infile to STDIN_FILENO in child failed");
	if (close(infile) == -1)
		perror("close infile in child failed");
	execute_command(&pipex->cmdarr[0][0], envp, pipex);
}

/*
Function to execute the parent process. Forks a child process to open 
the infile and execute first command.
*/
void	parent(char **argv, char **envp, t_pipex *pipex)
{
	pid_t	pid;
	int		pipe_fd[2];
	int		file;

	file = 0;
	if (pipe(pipe_fd) == -1)
		errormsg("pipeerr");
	pid = make_fork(pipex);
	if (pid == -1)
		errormsg("forkerr");
	if (pid == 0)
	{
		child(argv, pipe_fd, envp, pipex);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipe_fd[1]);
		file = fileopen(argv, pipex);
		dup2(file, STDOUT_FILENO);
		close(file);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		execute_command(&pipex->cmdarr[1][0], envp, pipex);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;
	int		status;

	status = 0;
	if (ac < 5)
		errormsg("syntaxerr");
	if (access(av[1], F_OK | R_OK) != 0)
		errormsg("accesserr");
	pipex = init_pipex(ac);
	cmdparser(av, pipex);
	parent(av, env, pipex);
	waitpid(pipex->pids[pipex->pid_created - 1], &status, 0);
	if (WIFEXITED(status))
	{
		pipex->exit_status = WEXITSTATUS(status);
		if (pipex->exit_status != 0)
			exit(EXIT_FAILURE);
	}
	cleanup_pipex(4, pipex);
	printf("Completed successfully\n");
	fflush(stdout);
	return (EXIT_SUCCESS);
}
