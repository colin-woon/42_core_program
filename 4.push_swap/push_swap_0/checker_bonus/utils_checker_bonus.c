/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:26:57 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/04 23:00:33 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void			get_operations_list(t_push_swap *data);
bool			is_correctly_sorted(t_push_swap *data);
void			call_operation(t_push_swap *data, t_operations op);
t_operations	string_to_operation(const char *op_str);
int				get_operation(int fd, char *line);

void	get_operations_list(t_push_swap *data)
{
	char*	op_str;
	int		gnl_status;
	bool	is_empty;

	gnl_status = 0;
	is_empty = false;
	op_str = malloc(sizeof(char) * 5);
	if (op_str == NULL)
	{
		free(op_str);
		data_error(data);
	}
	while (!is_empty)
	{
		gnl_status = get_operation(0, op_str);
		if (gnl_status == EXIT_FAILURE)
			{
				free(op_str);
				data_error(data);
			}
		if (ft_strlen(op_str) == 0)
			is_empty = true;
		if (is_empty)
			break ;
		save_operation(data, string_to_operation((const char* )op_str));
	}
    free(op_str);
}

int	get_operation(int fd, char *line)
{
	int		i;
	int		read_status;
	char	char_buffer;

	i = 0;
	char_buffer = ' ';
	while (char_buffer != '\n')
	{
		read_status = read(fd, &char_buffer, 1);
		if (read_status == -1)
			return (EXIT_FAILURE);
		if (read_status == 0)
			break ;
		line[i++] = char_buffer;
		if (i > 4)
			return (EXIT_FAILURE);
	}
	if ((i > 0 && line[i - 1] != '\n') || line[0] == '\n')
		return (EXIT_FAILURE);
	if (read_status == 0)
		line[0] = '\0';
	else
		line[i - 1] = '\0';
	return (EXIT_SUCCESS);
}

t_operations	string_to_operation(const char *op_str)
{
	if (!ft_strncmp(op_str, "sa", 2))
		return (sa);
	else if (!ft_strncmp(op_str, "sb", 2))
		return (sb);
	else if (!ft_strncmp(op_str, "ss", 2))
		return (ss);
	else if (!ft_strncmp(op_str, "pa", 2))
		return (pa);
	else if (!ft_strncmp(op_str, "pb", 2))
		return (pb);
	else if (!ft_strncmp(op_str, "ra", 2))
		return (ra);
	else if (!ft_strncmp(op_str, "rb", 2))
		return (rb);
	else if (!ft_strncmp(op_str, "rr", 2))
		return (rr);
	else if (!ft_strncmp(op_str, "rra", 3))
		return (rra);
	else if (!ft_strncmp(op_str, "rrb", 3))
		return (rrb);
	else if (!ft_strncmp(op_str, "rrr", 3))
		return (rrr);
	else
		return (null_op);
}


void	call_operation(t_push_swap *data, t_operations op)
{
	if (op == sa)
		swap_a(data);
	else if (op == sb)
		swap_b(data);
	else if (op == ss)
		swap_ab(data);
	else if (op == pa)
		push_a(data);
	else if (op == pb)
		push_b(data);
	else if (op == ra)
		rotate_a(data);
	else if (op == rb)
		rotate_b(data);
	else if (op == rr)
		r_rotate_ab(data);
	else if (op == rra)
		r_rotate_a(data);
	else if (op == rrb)
		r_rotate_b(data);
	else if (op == rrr)
		r_rotate_ab(data);
	else
		data_error(data);
}


bool	is_correctly_sorted(t_push_swap *data)
{
	t_list	*reader;

	reader = data->operations_list;
	while (reader)
	{
		call_operation(data, (t_operations)(uintptr_t) reader->content);
		reader = reader->next;
	}
	return (is_sorted(data) && is_full(&data->stack_a));
}

