/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:29:18 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/05 18:06:54 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	char	*last;

	last = NULL;
	while (*src != '\0')
	{
		if (*src == (char)c)
			last = (char *)src;
		src++;
	}
	if (c == '\0')
		return ((char *)src);
	return (last);
}
