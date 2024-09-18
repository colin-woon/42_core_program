/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:12:35 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/18 16:13:03 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
