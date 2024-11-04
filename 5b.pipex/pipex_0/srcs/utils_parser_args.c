/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:09:21 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/31 15:52:32 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		get_quote_count(char *av, char c);
char	*parse_spaces(char *str);
char	*parse_quotes_n_escape(char *str);

/* 
Parses three conditions:
- wc\ -l
- 'wc -l'
- file\'that\'uses\'this\' (stupid af)
 */
char	*parse_quotes_n_escape(char *str)
{
	int		i;
	int		j;
	char	*new_str;
	char	quote;
	char	backslash;

	i = -1;
	j = 0;
	quote = '\'';
	backslash = 92;
	new_str = str;
	while (str[++i])
	{
		if ((str[i] != quote && str[i] != backslash) || \
		(str[i] == backslash && str[i + 1] != quote && str[i + 1] != ' ') || \
		(i > 0 && str[i] == quote && str[i - 1] == backslash))
			new_str[j++] = str[i];
	}
	new_str[j] = '\0';
	return (new_str);
}

/*	
ASCII value
39 = '(single quote)
92 = \(backslash)

This replaces spaces with -1 for later parsing
 */
char	*parse_spaces(char *str)
{
	int			in_quote;
	int			i;

	in_quote = 0;
	i = -1;
	while (str[++i])
	{
		if (!in_quote && str[i] == 39)
			in_quote = 1;
		else if (in_quote && str[i] == 39)
			in_quote = 0;
		else if (!in_quote && str[i] == 92)
			i++;
		else if (!in_quote && str[i] == ' ')
			str[i] = FLAG_SPACE;
	}
	return (str);
}

int	get_quote_count(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			count++;
		if (str[i] == c && str[i - 1] == '\\' && count > 0)
			count--;
	}
	return (count);
}
