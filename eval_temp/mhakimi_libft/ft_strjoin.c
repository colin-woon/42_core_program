/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:04:21 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/10 21:39:43 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * (1) Create strlen as helper function.
 *
 * (2) Create a variable which join s1 and s2 later and
 * assign it malloc with size of char * (str 1 + str 2 + 1 for null terminator).
 *
 * (3) Guard malloc.
 *
 * (4) Assign values of s1 to str_join, then s2.
 *
 * (5) Assign null terminator to the end of str_join.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str_join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str_join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str_join == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str_join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str_join[i + j] = s2[j];
		j++;
	}
	str_join[i + j] = '\0';
	return (str_join);
}
