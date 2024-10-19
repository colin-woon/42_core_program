/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:36:13 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/19 22:41:01 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handler(int status, char *error_msg, int fd);

void	error_handler(int status, char *error_msg, int fd)
{
	if (status == EXIT_FAILURE)
		ft_putendl_fd(error_msg, fd);
	else if (status == -1)
	{
		perror(error_msg);
		exit(errno);
	}
	else if (status == 3)
	{
		ft_putendl_fd("Bad Args:\n\
		Correct		-> ./pipex <file1> <cmd1> <cmd2> <file2> \
		If here_doc	-> ./pipex here_doc <LIMITER> <cmd> <cmd1> <file>", fd);
	}
	else if (status == 4)
		ft_putendl_fd("Info Error", fd);
	else
		ft_putendl_fd("Undefined Error", fd);
	exit(EXIT_FAILURE);
}
