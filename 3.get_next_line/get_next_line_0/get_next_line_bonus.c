/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:26:05 by cwoon             #+#    #+#             */
/*   Updated: 2024/07/31 21:23:27 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd);
void	create_linked_list(t_list **list_ptr, int fd);
void	append_str_node(t_list **list_ptr, char *str_buffer, int fd);
char	*get_line(t_list *node_ptr);
void	update_list_after_newline(t_list **list_ptr);

char	*get_next_line(int fd)
{
	static t_list	*list[OPEN_MAX];
	char			*next_line;

	next_line = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || \
	read(fd, &next_line, 0) < 0)
		return (NULL);
	create_linked_list(list, fd);
	if (list[fd] == NULL)
		return (NULL);
	next_line = get_line(list[fd]);
	update_list_after_newline(&list[fd]);
	return (next_line);
}

void	create_linked_list(t_list **list_ptr, int fd)
{
	int		chars_read;
	char	*str_buffer;

	chars_read = 0;
	str_buffer = NULL;
	while (found_newline(list_ptr[fd]) == 0)
	{
		str_buffer = malloc(BUFFER_SIZE + 1);
		if (str_buffer == NULL)
			return ;
		chars_read = read(fd, str_buffer, BUFFER_SIZE);
		if (chars_read == 0)
		{
			free(str_buffer);
			return ;
		}
		str_buffer[chars_read] = '\0';
		append_str_node(list_ptr, str_buffer, fd);
	}
	return ;
}

void	append_str_node(t_list **list_ptr, char *str_buffer, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(list_ptr[fd]);
	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		list_ptr[fd] = new_node;
	else
		last_node->next_node = new_node;
	*new_node = (t_list) \
	{.file_buffer = str_buffer, .next_node = NULL};
	return ;
}

char	*get_line(t_list *node_ptr)
{
	int		line_length;
	char	*new_line;

	if (node_ptr == NULL)
		return (NULL);
	line_length = strlen_to_newline(node_ptr);
	new_line = malloc(line_length + 1);
	if (new_line == NULL)
		return (NULL);
	copy_list_to_line(node_ptr, new_line);
	return (new_line);
}

void	update_list_after_newline(t_list **list_ptr)
{
	t_list	*last_node;
	t_list	*new_node_after_newline;
	int		i_src;
	int		i_dest;
	char	*str_buffer;

	str_buffer = malloc(BUFFER_SIZE + 1);
	new_node_after_newline = malloc(sizeof(t_list));
	if (str_buffer == NULL || new_node_after_newline == NULL || \
	list_ptr == NULL)
		return ;
	last_node = find_last_node(*list_ptr);
	i_src = 0;
	i_dest = 0;
	while (last_node->file_buffer[i_src] != '\0' && \
	last_node->file_buffer[i_src] != '\n')
		i_src++;
	while (last_node->file_buffer[i_src] != '\0' && \
	last_node->file_buffer[++i_src] != '\0')
		str_buffer[i_dest++] = last_node->file_buffer[i_src];
	str_buffer[i_dest] = '\0';
	*new_node_after_newline = (t_list) \
	{.file_buffer = str_buffer, .next_node = NULL};
	clear_list(list_ptr, new_node_after_newline, str_buffer);
}

/*  #include <stdio.h>
int main()
{
	int	fd[2], no_of_lines;
	char *line_of_str;

	no_of_lines = 1;
	line_of_str = get_next_line(1000);
	fd[0] = open("test2.txt", O_RDONLY);
	while ((line_of_str = get_next_line(fd[0])))
	{
		printf("%d->%s", no_of_lines++, line_of_str);
		free(line_of_str);
	}

	line_of_str = get_next_line(1001);
	fd[1] = open("test.txt", O_RDONLY);
	while ((line_of_str = get_next_line(fd[1])))
	{
		printf("%d->%s", no_of_lines++, line_of_str);
		free(line_of_str);
	}

	line_of_str = get_next_line(1002);
	line_of_str = get_next_line(1003);
	line_of_str = get_next_line(1004);
	line_of_str = get_next_line(1005);

} */
