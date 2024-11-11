/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:28:37 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/10 21:45:21 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * (1) Reminder that strtrim only trim the beginning and end!
 *
 * (2) You need strlen, strchr, strlcpy as helper functions.
 *
 * (3) First While search value in set, if there is, index i will progresses.
 * But if there is no, no change in index.
 *
 * (4) Second While search value in set from the end.
 * Same the index z will decreased if there is.
 * But if there is no, no change.
 *
 * (5) Now we have start and end index, which are index i and z.
 *
 * (6) Allocate malloc to str_trim
 * which size of char * (index z - 1 + 1 for null terminator).
 *
 * (7) Strlcpy will copy the s1 into str_trim
 * from index i to z.
 *
 * (8) Return str_trim.
 */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		z;
	char	*str_trim;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	z = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (z > i && ft_strchr(set, s1[z - 1]) != NULL)
		z--;
	str_trim = malloc(sizeof(char) * (z - i + 1));
	if (str_trim == NULL)
		return (NULL);
	ft_strlcpy(str_trim, &s1[i], (z - i + 1));
	return (str_trim);
}
