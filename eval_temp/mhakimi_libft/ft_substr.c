/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:21:22 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/10 21:32:38 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * 
 * (1) Create substitute variable and assigned malloc.
 * (2) Malloc is the size of (char * length of substring + null terminator)
 * (3) Guard malloc - If failed, return NULL.
 * (4) While substring index is not more than its length,
 * and main string is not null terminator,
 * assign value of s to sub.
 * (5) Assign null terminator to the end of sub.
 * (6) Return sub.
 */

#include "libft.h"

static char	*ft_allocate_empty_string(void)
{
	char	*empty;

	empty = malloc(1);
	if (empty)
		empty[0] = '\0';
	return (empty);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_allocate_empty_string());
	if (start + len > s_len)
		len = s_len - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
