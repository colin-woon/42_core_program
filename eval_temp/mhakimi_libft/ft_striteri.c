/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:56:24 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/10 21:05:02 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * (1) The difference between ft_striteri and ft_strmapi are:
 * ft_striteri modifies original str while mapi create new
 * str, allocate mem, then modify + add null term, and return said new str.
 *
 * (2) While going through the original string, apply the
 * string into function f at index (s + i).
 *
 * (3) (s + i) same as &s[i].
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
