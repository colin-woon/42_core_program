/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:09:40 by cwoon             #+#    #+#             */
/*   Updated: 2024/11/04 14:01:10 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

// PIPES
# define READ_END 0
# define WRITE_END 1
# define FLAG_SPACE -1

/* custom err msg */
# define DIR_ERR_MSG "pipex: no such file or directory: "
# define PER_ERR_MSG "pipex: permission denied: "
# define CMD_ERR_MSG "pipex: command not found: "

// CUSTOM ERROR CODE
# define PATH_ERR -2
# define ARG_ERR 3
# define INFO_ERR 4
# define PIPEFD_ERR 5

typedef struct s_files
{
	char	*infile;
	int		in_f_ko;
	int		in_r_ko;
	int		in_fd;
	char	*outfile;
	int		out_f_ko;
	int		out_w_ko;
	int		out_fd;
	int		is_here_doc;
	char	*limiter;
}	t_files;

typedef struct s_cmd
{
	int				index;
	char			*name;
	char			*path;
	char			**flags;
	int				not_exist;
	int				not_exec;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_info
{
	t_files	*files;
	t_list	*path;
	t_cmd	*cmd;
	t_cmd	*cmd_start;
	int		**pipefd;
	int		total_cmd;
	pid_t	last_pid;
	int		exit_code;
}	t_info;

// Utils Error
void	error_handler(int status, char *error_msg, int fd);

// Utils
int		is_bad_args(int ac, char **av);
int		**get_pipefd(t_info *info);
int		get_exit_code(int status, t_info *info);
int		cmd_lstsize(t_cmd *start);

// Utils Free
void	clean_up(t_info *info);
void	close_files(t_files *files);
void	close_pipefd(int total_cmd, int **pipefd);

// Utils cmd_lst
void	cmd_lstclear(t_cmd **start, void (*del)(void *));
void	cmd_lstdelone(t_cmd *cmd, void (*del)(void *));
t_cmd	*cmd_lstnew(char **split_cmd, int index);
t_cmd	*cmd_lstappend(t_cmd **start, t_cmd *new_cmd);
t_cmd	*cmd_lstlast(t_cmd *start);

// Parser
char	**parse_args(int ac, char **av);
t_list	*parse_path(char **envp, t_info *info);
t_files	*parse_files(int ac, char **av);
t_cmd	*parse_cmd(char **av, t_info *info);

// Execution
void	execute_cmd(t_info *info, char **envp);
void	safe_dup(int new_fd, int old_fd, t_info *info);
void	dup_first_cmd(t_info *info);
void	dup_mid_cmd(t_info *info);
void	dup_last_cmd(t_info *info);

// Utils Parser Args
int		get_quote_count(char *av, char c);
char	*parse_spaces(char *str);
char	*parse_quotes_n_escape(char *str);

// Utils Parser Path
t_list	*get_path_list(char **all_paths, t_info *info);

// Utils Parser Files
void	open_files(t_files *files);

// Utils Parser Cmd
int		set_cmd_infos(t_cmd **start, t_list *path);
void	get_cmd_path(t_cmd *cmd, t_list *path);

#endif
