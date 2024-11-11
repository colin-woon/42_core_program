/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:18:03 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/10 20:58:57 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * (1) char (*f)(unsigned int, char) means it created
 * a function named f which has char type. This function
 * takes 2 parameters which is unsigned int and char.
 *
 * (2) function f takes char s as 1st argument, and 
 * index i as 2nd.
 *
 * (3) Check if s or f is NULL.
 *
 * (4) Allocate memory for new_str which the size of char *
 * length of s + 1 for null terminator.
 *
 * (5) Guard malloc.
 *
 * (6) Assign the outputs of f(s,i) to new_str while loop.
 *
 * (7) Assign null terminator to new_str at the end.
 *
 * (8) Return new_str.
 */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	if (s == NULL || f == NULL)
		return (NULL);
	new_str = malloc(sizeof(char) * ((ft_strlen(s)) + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
