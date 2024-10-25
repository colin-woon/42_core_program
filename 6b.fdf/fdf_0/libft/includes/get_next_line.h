/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:26:31 by cwoon             #+#    #+#             */
/*   Updated: 2024/10/11 21:26:37 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# define TRIG -1

int		strle(const char *s);
int		idx_of(char *buf, char c);
int		itrig(char *buf);
void	clr_buf(char buf[], int j, char val);
char	*init(char **line, char buf[], int *eof);
char	*finall(char *line, char buf[], int eof);
char	*get_next_line(int fd);
char	*strj(char *s1, char *s2);
char	*subs(char *s, int start, int len);

#endif
