/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:36:21 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/04 13:46:37 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		set_cmd_infos(t_cmd **start, t_list *path);
void	get_cmd_path(t_cmd *cmd, t_list *path);

/* 
Deals with absolute path commands
- instantly checks accessibility
- saves it as a path itself

For normal commands
- checks command accessibility with the 2D array of parsed paths
*/
int	set_cmd_infos(t_cmd **start, t_list *path)
{
	t_cmd	*cmd_node;

	cmd_node = *start;
	while (cmd_node)
	{
		cmd_node->path = NULL;
		if (!cmd_node->name)
			cmd_node->name = " ";
		if (ft_strchr(cmd_node->name, '/'))
		{
			cmd_node->not_exec = access(cmd_node->name, X_OK);
			cmd_node->not_exist = access(cmd_node->name, F_OK);
			cmd_node->path = ft_strdup(cmd_node->name);
		}
		else
			get_cmd_path(cmd_node, path);
		if (!cmd_node->path)
		{
			cmd_lstclear(start, &free);
			return (PATH_ERR);
		}
		cmd_node = cmd_node->next;
	}
	return (0);
}
/* 
Loops through all PATH in the env to 
find the accessible absolute path for the command

If found, sets the path and accessibility results
 */
void	get_cmd_path(t_cmd *cmd, t_list *path)
{
	char	*tmp_path;
	char	*tmp_name;

	tmp_name = ft_strjoin("/", cmd->name);
	if (!tmp_name)
		return ;
	while (path)
	{
		tmp_path = ft_strjoin(path->content, tmp_name);
		if (!tmp_path)
			return (free(tmp_name));
		if (!access(tmp_path, F_OK))
		{
			cmd->path = tmp_path;
			cmd->not_exist = access(tmp_path, F_OK);
			cmd->not_exec = access(tmp_path, X_OK);
			return (free(tmp_name));
		}
		free(tmp_path);
		path = path->next;
	}
	free(tmp_name);
	cmd->path = ft_strdup(cmd->name);
	cmd->not_exist = -1;
	cmd->not_exec = -1;
}
