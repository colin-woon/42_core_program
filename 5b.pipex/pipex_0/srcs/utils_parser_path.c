/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:29:25 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/13 00:47:57 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*get_path_list(char **all_paths, t_info *info);

t_list	*get_path_list(char **all_paths, t_info *info)
{
	int		i;
	char	*content;
	t_list	*new;
	t_list	*path;

	i = -1;
	path = NULL;
	while (all_paths[++i])
	{
		content = ft_strdup(all_paths[i]);
		new = ft_lstnew(content);
		if (!content || !new)
		{
			free(content);
			free(new);
			ft_lstclear(&path, &free);
			ft_free_2d_array(all_paths);
			clean_up(info);
			exit(PATH_ERR);
		}
		ft_lstadd_back(&path, new);
	}
	ft_free_2d_array(all_paths);
	return (path);
}
