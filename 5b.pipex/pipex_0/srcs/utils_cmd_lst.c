/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:50:55 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/19 21:46:54 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_lstclear(t_cmd **start, void (*del)(void *));
void	cmd_lstdelone(t_cmd *cmd, void (*del)(void *));
t_cmd	*cmd_lstnew(char **split_cmd, int index);
t_cmd	*cmd_lstappend(t_cmd **start, t_cmd *new_cmd);
t_cmd	*cmd_lstlast(t_cmd *start);

void	cmd_lstclear(t_cmd **start, void (*del)(void *))
{
	t_cmd	*tmp;

	if (!start || !*start)
		return ;
	while (*start)
	{
		tmp = (*start)->next;
		cmd_lstdelone(*start, del);
		*start = tmp;
	}
}

void	cmd_lstdelone(t_cmd *cmd, void (*del)(void *))
{
	if (!del || !cmd)
		return ;
	ft_free_2d_array(cmd->flags);
	if (cmd->path)
		(*del)(cmd->path);
	free(cmd);
}

t_cmd	*cmd_lstnew(char **split_cmd, int index)
{
	t_cmd	*new_cmd;

	if (split_cmd == NULL)
		return (NULL);
	new_cmd = malloc (sizeof(t_cmd));
	if (!new_cmd)
	{
		ft_free_2d_array(split_cmd);
		return (NULL);
	}
	new_cmd->flags = split_cmd;
	new_cmd->name = split_cmd[0];
	new_cmd->path = NULL;
	new_cmd->index = index;
	new_cmd->next = NULL;
	return (new_cmd);
}

// Start is a pointer to a linked list, be aware
t_cmd	*cmd_lstappend(t_cmd **start, t_cmd *new_cmd)
{
	t_cmd	*ptr;

	if (!start)
		return (NULL);
	if (!new_cmd)
		return (*start);
	if (start)
	{
		if (!*start)
		{
			*start = new_cmd;
			return (*start);
		}
		ptr = cmd_lstlast(*start);
		ptr->next = new_cmd;
	}
	return (*start);
}

t_cmd	*cmd_lstlast(t_cmd *start)
{
	if (!start)
		return (NULL);
	while (start->next)
		start = start->next;
	return (start);
}
