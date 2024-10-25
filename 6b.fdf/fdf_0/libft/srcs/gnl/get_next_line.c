/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:26:11 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/11 21:26:52 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*init(char **line, char buf[], int *eof)
{
	buf[BUFFER_SIZE] = '\0';
	*eof = 1;
	*line = malloc(sizeof(char));
	if (!*line)
		return (NULL);
	**line = '\0';
	return (*line);
}

void	clr_buf(char buf[], int j, char val)
{
	int	i;

	if (j < 0)
		j = BUFFER_SIZE - 1;
	i = 0;
	while (buf[i] && i <= j)
		buf[i++] = val;
}

char	*finall(char *line, char buf[], int eof)
{
	if (eof == 0)
		return (line);
	if (eof < 0 || !strle(line))
	{
		free(line);
		return (NULL);
	}
	else
	{
		clr_buf(buf, -1, '\0');
		return (line);
	}
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*line;
	int				j;
	int				eof;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || !init(&line, buf, &eof))
		return (NULL);
	while (eof > 0)
	{
		j = idx_of(buf, '\n');
		if (j != -1)
		{
			line = strj(line, subs(buf, itrig(buf), j + 1 - itrig(buf)));
			clr_buf(buf, j, TRIG);
			return (line);
		}
		line = strj(line, subs(buf, itrig(buf), strle(buf) - itrig(buf)));
		if (!line)
			return (NULL);
		clr_buf(buf, -1, '\0');
		eof = read(fd, buf, BUFFER_SIZE);
	}
	return (finall(line, buf, eof));
}
