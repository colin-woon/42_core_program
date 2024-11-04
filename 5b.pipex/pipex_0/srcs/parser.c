/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:10:56 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/04 16:33:59 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_args(int ac, char **av);
t_list	*parse_path(char **envp, t_info *info);
t_files	*parse_files(int ac, char **av);
t_cmd	*parse_cmd(char **av, t_info *info);

/*	
& - bitwise AND operation 
easy way to check ODD or EVEN number
eg:
	quote_count = 5
	Binary:       0101
				&
	Binary:       0001
	Result:       0001 (true, odd)

	quote_count = 4
	Binary:       0100
				&
	Binary:       0001
	Result:       0000 (false, even)
*/
char	**parse_args(int ac, char **av)
{
	int	i;
	int	quote_count;

	i = -1;
	if (ac > 1)
	{
		while (av[++i])
		{
			quote_count = get_quote_count(av[i], '\'');
			if (quote_count & 1)
				error_handler(EXIT_FAILURE, \
				"Error: Odd number of quotes", STDERR_FILENO);
			av[i] = parse_spaces(av[i]);
			av[i] = parse_quotes_n_escape(av[i]);
		}
	}
	return (av);
}

/* 
Parses PATH into a 2D array, then parse it again to a linked list of paths
 */
t_list	*parse_path(char **envp, t_info *info)
{
	t_list	*path;
	char	**all_paths;

	path = NULL;
	while (*envp)
	{
		if (!ft_strncmp("PATH", *envp, 4))
			break ;
		envp++;
	}
	if (*envp)
	{
		all_paths = ft_split(ft_strchr(*envp, '=') + 1, ':');
		if (!all_paths)
		{
			clean_up(info);
			exit(PATH_ERR);
		}
		path = get_path_list(all_paths, info);
	}
	return (path);
}

/* 
Checks for here_doc(saves limiter too), and init files structure, 
Checks accessibility before opening
 */
t_files	*parse_files(int ac, char **av)
{
	t_files	*files;

	files = malloc(sizeof(t_files));
	if (files == NULL)
		return (NULL);
	if (!ft_strncmp(av[1], "here_doc", ft_strlen(av[1])))
	{
		files->infile = NULL;
		files->is_here_doc = 1;
		files->limiter = av[2];
		files->in_f_ko = 0;
		files->in_r_ko = 0;
	}
	else
	{
		files->infile = av[1];
		files->is_here_doc = 0;
		files->in_f_ko = access(av[1], F_OK);
		files->in_r_ko = access(av[1], R_OK);
	}
	files->outfile = av[ac - 1];
	files->out_f_ko = access(av[ac - 1], F_OK);
	files->out_w_ko = access(av[ac - 1], W_OK);
	open_files(files);
	return (files);
}

/* 
Loop condition checks file2 param & after it.
Parses the commands into a linked list
Each command saves its flags into a 2D array and index
 */
t_cmd	*parse_cmd(char **av, t_info *info)
{
	t_cmd	*start;
	t_cmd	*cmd_node;
	char	**split_cmd;
	int		i;

	av++;
	if (info->files->is_here_doc)
		av++;
	start = NULL;
	i = -1;
	while (*(av + 2))
	{
		++av;
		split_cmd = ft_split(*(av), FLAG_SPACE);
		if (split_cmd == NULL)
			return (cmd_lstclear(&start, &free), NULL);
		cmd_node = cmd_lstnew(split_cmd, ++i);
		if (cmd_node == NULL)
			return (cmd_lstclear(&start, &free), NULL);
		start = cmd_lstappend(&start, cmd_node);
	}
	if (set_cmd_infos(&start, info->path) == PATH_ERR)
		return (NULL);
	return (start);
}
