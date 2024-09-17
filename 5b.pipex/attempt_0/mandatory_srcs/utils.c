/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:11:34 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/17 19:27:26 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handler(int status, char *status_msg, int fd);
int		open_file(char *file_name, int std_fd);

void	error_handler(int status, char *status_msg, int fd)
{
	if (status == EXIT_SUCCESS || status > 1)
		return ;
	else if (status == EXIT_FAILURE || status == -1)
	{
		ft_putstr_fd("Error: ", fd);
		ft_putendl_fd(status_msg, fd);
	}
	else
		ft_putendl_fd("Undefined Error", fd);
	exit(status);
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
		error_handler(EXIT_FAILURE, strerror(errno), STDERR_FILENO);
	return (fd);
}
