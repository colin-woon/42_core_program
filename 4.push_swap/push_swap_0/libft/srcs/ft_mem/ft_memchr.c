/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:43:09 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/23 18:27:35 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
/*
Locates a specified character in a string with a limited search option
Input	:String `*src`, character to find `c` (integer promotion applied),
		range of comparison `n`
Output	:Returns the pointer pointing to where the character is found
 */
void	*ft_memchr(const void *src, int c, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)src;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)src + i);
		i++;
	}
	return (NULL);
}
