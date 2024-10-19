/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:24:06 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/19 21:44:12 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(t_info *info, char **envp);
void	safe_dup(int new_fd, int old_fd, t_info *info);
void	dup_first_cmd(t_info *info);
void	dup_mid_cmd(t_info *info);
void	dup_last_cmd(t_info *info);

void	execute_cmd(t_info *info, char **envp)
{
	if (info->cmd->index == 0)
		dup_first_cmd(info);
	else if (info->cmd->next)
		dup_mid_cmd(info);
	else
		dup_last_cmd(info);
	if (info->cmd->not_exist)
	{
		if (!ft_strchr(info->cmd->name, '/'))
			ft_putendl_fd(CMD_ERR_MSG, STDERR_FILENO);
		else
			ft_putendl_fd(DIR_ERR_MSG, STDERR_FILENO);
		clean_up(info);
		exit(EXIT_FAILURE);
	}
	close_pipefd(info->cmd_nb, info->pipefd);
	close_files(info->files);
	if (execve(info->cmd->path, info->cmd->flags, envp) == -1)
	{
		perror("pipex (execve)");
		clean_up(info);
		exit(EXIT_FAILURE);
	}
}

void	dup_first_cmd(t_info *info)
{
	close(info->pipefd[info->cmd->index][READ_END]);
	safe_dup(info->pipefd[info->cmd->index][WRITE_END], STDOUT_FILENO, info);
	if (!info->files->in_f_ko && !info->files->in_r_ko)
		safe_dup(info->files->in_fd, STDIN_FILENO, info);
	else
	{
		close(info->pipefd[info->cmd->index][WRITE_END]);
		if (info->files->in_f_ko)
			ft_putendl_fd(DIR_ERR_MSG, STDERR_FILENO);
		else if (info->files->in_r_ko)
			ft_putendl_fd(PER_ERR_MSG, STDERR_FILENO);
		clean_up(info);
		exit(EXIT_FAILURE);
	}
}

void	dup_mid_cmd(t_info *info)
{
	close(info->pipefd[info->cmd->index - 1][WRITE_END]);
	close(info->pipefd[info->cmd->index][READ_END]);
	safe_dup(info->pipefd[info->cmd->index - 1][READ_END], STDIN_FILENO, info);
	safe_dup(info->pipefd[info->cmd->index][WRITE_END], STDOUT_FILENO, info);
}

void	dup_last_cmd(t_info *info)
{
	safe_dup(info->pipefd[info->cmd->index - 1][READ_END], STDIN_FILENO, info);
	if (!info->files->out_w_ko)
		safe_dup(info->files->out_fd, STDOUT_FILENO, info);
	else
	{
		close(info->pipefd[info->cmd->index - 1][READ_END]);
		ft_putendl_fd(PER_ERR_MSG, STDERR_FILENO);
		info->exit_code = EXIT_FAILURE;
		clean_up(info);
		exit(EXIT_FAILURE);
	}
}

void	safe_dup(int new_fd, int old_fd, t_info *info)
{
	if (dup2(new_fd, old_fd) == -1)
	{
		perror("pipex (dup2)");
		clean_up(info);
		exit(EXIT_FAILURE);
	}
}
