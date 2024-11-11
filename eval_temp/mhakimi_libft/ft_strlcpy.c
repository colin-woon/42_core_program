/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:02:01 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/10 21:01:05 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * (1) strlcpy will return number of characters of source string,
 * NOT just the copied ones.
 *
 * (2) if size empty, return total numb string,
 * without passing while.
 *
 * (3) Assign value of src to dest up to size - 1.
 * Because size in strlcpy refers to buffer size,
 * NOT length.
 *
 * (4) Size will include null terminator. Length will not.
 *
 * (5) In summary, strlcpy input is buffer size, 
 * but output is length.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (size == 0)
		return (i);
	j = 0;
	while (src[j] != '\0' && j < (size - 1))
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
