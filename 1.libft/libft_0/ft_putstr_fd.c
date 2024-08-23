/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:46:37 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/23 18:27:35 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
/*
NAME
    ft_putstr_fd -- write a string on a specified file descriptor
SYNOPSIS
    void ft_putstr_fd(char *s, int fd);
DESCRIPTION
    Write the string s on the file descriptor fd.
PARAMETERS
    s: string to write
    fd: file descriptor on which to write
*/
void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}
