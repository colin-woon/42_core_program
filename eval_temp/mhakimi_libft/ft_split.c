/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:29:06 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/10 21:52:32 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * (0) ft_split uses ft_strlen, ft_substr, ft_strchr, and
 * ft_countword.
 *
 * (1) ft_countword - count each letter, skip delimiter c.
 *
 * (2) The if that count++ surrounded by two while which
 * makes sure pointer moving forward everytime encounter
 * a character.
 *
 * (3) *new_str allocated memory of char * counted words + 1.
 *
 * (4) guard malloc.
 *
 * (5) first while makes sure pointer keep moving skipping
 * delimiters until found first character.
 *
 * (6) Check using strchr.
 * The if checks if there is next delimiters after
 * current character at current pointer and assign the
 * length to be current pointer until the end.
 *
 * (7) The else assign the length as the next delimiter -
 * start of current pointer.
 *
 * (8) Everytime the word is append into new_str using
 * ft_substr.
 *
 * (9) The pointer moving at word_len's length. Process
 * repeat until the end.
 *
 * (10) NULL is assign at the end of array (like null term)
 *
 * (11) new_str is returned.
 */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (*s == '\0')
		return (0);
	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	size_t	word_len;
	int		i;

	new_str = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			if (ft_strchr(s, c) == NULL)
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			new_str[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	new_str[i] = NULL;
	return (new_str);
}
