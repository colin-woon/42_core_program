/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:59:01 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/20 13:21:19 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_bad_args(int ac, char **av);
int	**get_pipefd(t_info *info);
int	get_exit_code(int status, t_info *info);
int	cmd_lstsize(t_cmd *start);

int	is_bad_args(int ac, char **av)
{
	if (ac < 5)
		return (1);
	else if (ac < 6 && !ft_strncmp(av[1], "here_doc", ft_strlen("here_doc")))
		return (1);
	else
		return (0);
}

// number of pipes needed is always one less than number of commands
// only 2 fds needed for READ and WRITE for each pipe
int	**get_pipefd(t_info *info)
{
	int	i;
	int	**pipefd;

	pipefd = malloc((info->cmd_nb - 1) * sizeof(int *));
	if (!pipefd)
		return (NULL);
	i = 0;
	while (i < info->cmd_nb - 1)
	{
		pipefd[i] = malloc(2 * sizeof(int));
		if (!pipefd[i] || pipe(pipefd[i]) == -1)
		{
			perror("Unable to get pipefd");
			ft_free_int_matrix(pipefd, i + 1);
			return (NULL);
		}
		i++;
	}
	return (pipefd);
}

int	get_exit_code(int status, t_info *info)
{
	if (info->files->out_w_ko)
		return (1);
	info->cmd = cmd_lstlast(info->cmd_start);
	if (info->cmd->not_exist)
		return (127);
	if (info->cmd->not_exec)
		return (126);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (status);
}

int	cmd_lstsize(t_cmd *start)
{
	int	i;

	i = 0;
	while (start)
	{
		i++;
		start = start->next;
	}
	return (i);
}
