/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:08:11 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/18 15:50:47 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

void	error_handler(int status, char *error_msg, int fd);
int		open_file(char *file_name, int std_fd);
char	*get_path(char *cmd, char **envp);
void	execute_cmd(char *av_cmd, char **envp);
