/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleow <bleow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:02:54 by bleow             #+#    #+#             */
/*   Updated: 2024/10/28 22:11:03 by bleow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>  
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include <stddef.h>
# include <sys/wait.h>
# include <sys/types.h>

# define MAX_ARGS 4

typedef struct s_pipex
{
	int		pid_created;
	int		args;
	int		c;
	int		a;
	int		exit_status;
	char	***cmdarr;
	char	**split_cmd;
	pid_t	*pids;
}	t_pipex;

int		fileopen(char **argv, t_pipex *pipex);
pid_t	make_fork(t_pipex *pipex);
void	child(char **argv, int *pipe_fd, char **envp, t_pipex *pipex);
void	parent(char **argv, char **envp, t_pipex *pipex);
char	**find_env_path(char **env);
void	cmdspaces(int i, char **argv, t_pipex *pipex);
void	cmdparser(char **argv, t_pipex *pipex);
void	execute_command(char **cmd, char **env, t_pipex *pipex);
t_pipex	*init_pipex(int argc);
void	mem_alloc_cmdarr(t_pipex *pipex, int argc);
char	*find_cmd_path(char *cmd, char **env);
char	*build_path(const char *path, const char *cmd);
char	*errormsg(char *msg);
void	cleanup_pipex(int type, t_pipex *pipex);
void	cleanup_paths(char **paths);

#endif
