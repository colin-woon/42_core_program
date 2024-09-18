/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:11:34 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/18 20:09:44 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handler(int status, char *error_msg, int fd);
char	*get_env(char *env_name, char **envp);
char	*get_path(char *cmd, char **envp);
void	execute_cmd(char *av_cmd, char **envp);

void	error_handler(int status, char *error_msg, int fd)
{
	if (status == EXIT_SUCCESS || status > 1)
		return ;
	else if (status == EXIT_FAILURE)
		ft_putendl_fd(error_msg, fd);
	else if (status == -1)
		perror(error_msg);
	else
		ft_putendl_fd("Undefined Error", fd);
	exit(EXIT_FAILURE);
}

char	*get_env(char *env_name, char **envp)
{
	int		i_env;
	int		i_str;
	char	*current_env;

	i_env = 0;
	while (envp[i_env])
	{
		i_str = 0;
		while (envp[i_env][i_str] && envp[i_env][i_str] != '=')
			i_str++;
		current_env = ft_substr(envp[i_env], 0, i_str);
		if (ft_strncmp(current_env, env_name, ft_strlen(env_name + 1)) == 0)
		{
			free(current_env);
			return (envp[i_env] + i_str + 1);
		}
		free(current_env);
		i_env++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	**all_paths;
	char	*cmd_path;
	char	*path_prefix;
	int		i;

	i = 0;
	while(ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	all_paths = ft_split(envp[i] + 4 + 1, ':');
	i = -1;
	while (all_paths[++i])
	{
		path_prefix = ft_strjoin(all_paths[i], "/");
		cmd_path = ft_strjoin(path_prefix, cmd);
		free(path_prefix);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	ft_free_2d_array(all_paths);
	return (0);
}

void	execute_cmd(char *av_cmd, char **envp)
{
	char	**str_cmd;
	char	*path;

	str_cmd = ft_split(av_cmd, ' ');
	path = get_path(str_cmd[0], envp);
	if (path == 0)
	{
		ft_free_2d_array(str_cmd);
		error_handler(-1, "Path Error", 2);
	}
	if (execve(path, str_cmd, envp) == -1)
	{
		free(path);
		ft_free_2d_array(str_cmd);
		error_handler(-1, "Execute Error", 2);
	}
}
