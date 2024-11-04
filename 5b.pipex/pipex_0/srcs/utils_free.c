/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:43:01 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/04 14:01:10 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clean_up(t_info *info);
void	close_files(t_files *files);
void	close_pipefd(int total_cmd, int **pipefd);

void	clean_up(t_info *info)
{
	if (info->files)
	{
		close_files(info->files);
		if (info->files->is_here_doc)
			unlink("/tmp/.here_doc.txt");
		free(info->files);
	}
	if (info->total_cmd && info->pipefd)
	{
		close_pipefd(info->total_cmd, info->pipefd);
		ft_free_int_matrix(info->pipefd, info->total_cmd);
	}
	if (info->path)
		ft_lstclear(&(info->path), &free);
	if (info->cmd_start)
		cmd_lstclear(&(info->cmd_start), &free);
	free(info);
}

void	close_files(t_files *files)
{
	if (files->in_fd > 0)
		close(files->in_fd);
	if (files->out_fd > 0)
		close(files->out_fd);
}

void	close_pipefd(int total_cmd, int **pipefd)
{
	int	i;

	if (!total_cmd || !pipefd)
		return ;
	i = -1;
	while (++i < total_cmd - 1)
	{
		close(pipefd[i][WRITE_END]);
		close(pipefd[i][READ_END]);
	}
}
