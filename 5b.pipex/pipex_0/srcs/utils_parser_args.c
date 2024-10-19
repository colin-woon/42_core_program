/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:09:21 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/19 21:46:13 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		get_quote_count(char *av, char c);
char	*parse_spaces(char *str);
char	*parse_single_quotes(char *str);

char	*parse_single_quotes(char *str)
{
	int		i;
	int		j;
	char	*new_str;
	char	quote;
	char	backslash;

	i = -1;
	j = 0;
	quote = '\'';
	backslash = '\\';
	new_str = str;
	while (str[++i])
	{
		if (str[i] != quote && str[i] != backslash)
			new_str[j++] = str[i];
		else if (str[i] == backslash \
		&& str[i + 1] != quote && str[i + 1] != ' ')
			new_str[j++] = str[i];
		else if (i > 0 && str[i] == quote && str[i - 1] == backslash)
			new_str[j++] = str[i];
	}
	new_str[j] = '\0';
	return (new_str);
}

char	*parse_spaces(char *str)
{
	int		is_in_quote;
	int		i;
	char	quote;
	char	backslash;

	quote = '\'';
	backslash = '\\';
	is_in_quote = 0;
	i = -1;
	while (str[i])
	{
		if (!is_in_quote && str[i] == quote)
			is_in_quote = 1;
		else if (is_in_quote && str[i] == quote)
			is_in_quote = 0;
		else if (!is_in_quote && str[i] == backslash && str[i + 1] == ' ')
			i++;
		else if (!is_in_quote && str[i] == ' ')
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
