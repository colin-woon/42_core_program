/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:08:08 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/04 16:34:13 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_info	*init_info(int ac, char **av, char **envp);
void	run_pipex(t_info *info, char **envp);
void	wait_cmds(t_info *info);

int	main(int ac, char **av, char **envp)
{
	t_info	*info;
	int		exit_code;

	if (is_bad_args(ac, av))
		error_handler(ARG_ERR, NULL, STDERR_FILENO);
	av = parse_args(ac, av);
	info = init_info(ac, av, envp);
	if (!info)
		error_handler(INFO_ERR, NULL, 2);
	info->pipefd = get_pipefd(info);
	if (!info->pipefd)
	{
		clean_up(info);
		return (INFO_ERR);
	}
	run_pipex(info, envp);
	exit_code = get_exit_code(info->exit_code, info);
	clean_up(info);
	return (exit_code);
}

t_info	*init_info(int ac, char **av, char **envp)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->exit_code = 0;
	info->total_cmd = 0;
	info->cmd_start = NULL;
	info->pipefd = NULL;
	info->path = parse_path(envp, info);
	info->files = parse_files(ac, av);
	if (!info->files)
		return (clean_up(info), NULL);
	info->cmd = parse_cmd(av, info);
	if (!info->cmd)
		return (clean_up(info), NULL);
	info->cmd_start = info->cmd;
	info->total_cmd = cmd_lstsize(info->cmd_start);
	return (info);
}

/* 
Child Process (pid = 0): Focuses on execution, execve is indirectly
the I/O blocking feature, the command will wait for STDIN for input
Parent Process (pid >0): Focuses on closing pipes and incrementing
 */
void	run_pipex(t_info *info, char **envp)
{
	pid_t	pid;

	while (info->cmd)
	{
		pid = fork();
		if (pid == -1)
			perror("Fork error");
		if (pid == 0)
			execute_cmd(info, envp);
		if (pid > 0)
		{
			if (!info->cmd->next)
				info->last_pid = pid;
			if (info->cmd->index > 0)
				close(info->pipefd[info->cmd->index - 1][WRITE_END]);
			if (info->cmd->index > 1)
				close(info->pipefd[info->cmd->index - 2][READ_END]);
		}
		info->cmd = info->cmd->next;
	}
	close(info->pipefd[info->total_cmd - 2][READ_END]);
	wait_cmds(info);
}

void	wait_cmds(t_info *info)
{
	int		child_status;
	pid_t	killed_child_pid;

	killed_child_pid = 0;
	while (killed_child_pid != -1)
	{
		if (killed_child_pid == info->last_pid)
			info->exit_code = child_status;
		killed_child_pid = wait(&child_status);
	}
}
