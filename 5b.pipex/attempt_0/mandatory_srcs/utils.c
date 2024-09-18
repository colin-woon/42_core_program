/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:11:34 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/17 20:39:27 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handler(int status, char *error_msg, int fd);
int		open_file(char *file_name, int std_fd);

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

int	open_file(char *file_name, int std_fd)
{
	int	fd;

	fd = 0;
	if (std_fd == STDIN_FILENO)
		fd = open(file_name, O_RDONLY, 0777);
	else if (std_fd == STDOUT_FILENO)
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error_handler(-1, "File Error", 2);
	return (fd);
}

char	*get_path(char *cmd, char envp)
{

}
