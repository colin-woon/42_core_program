/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:35:45 by cwoon             #+#    #+#             */
/*   Updated: 2024/07/31 16:02:20 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_list
{
	char			*file_buffer;
	struct s_list	*next_node;
}	t_list;

char	*get_next_line(int fd);
void	create_linked_list(t_list **list_ptr, int fd);
int		found_newline(t_list *node_ptr);
void	append_str_node(t_list **list_ptr, char *str_buffer, int fd);
t_list	*find_last_node(t_list *node_ptr);
char	*get_line(t_list *node_ptr);
int		strlen_to_newline(t_list *node_ptr);
void	copy_list_to_line(t_list *node_ptr, char *new_line);
void	update_list_after_newline(t_list **list_ptr);
void	clear_list(t_list **list_ptr, t_list *new_node_after_newline, \
char *str_buffer);

#endif
