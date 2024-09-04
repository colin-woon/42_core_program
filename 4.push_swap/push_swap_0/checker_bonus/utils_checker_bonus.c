/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:26:57 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/05 02:46:04 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void			get_operations_list(t_push_swap *data);
bool			is_correctly_sorted(t_push_swap *data);
void			call_operation(t_push_swap *data, t_operations op);
t_operations	string_to_operation(const char *op_str);

void	get_operations_list(t_push_swap *data)
{
	char	char_buffer;
	char	op_str[4];
	int		i;
	int		reading;

	i = 0;
	reading = 1;
	ft_bzero(op_str, 4);
	while (reading)
	{
		reading = read(0, &char_buffer, 1);
		if (reading == 0)
			break ;
		if (char_buffer == '\n')
		{
			op_str[i] = '\0';
			// ft_printf("Operation read: '%s'\n", op_str);
			save_operation(data, string_to_operation((const char *)op_str));
			i = 0;
			ft_bzero(op_str, 4);
		}
		else if (i < 3)
			op_str[i++] = char_buffer;
	}
}

t_operations	string_to_operation(const char *op_str)
{
	if (!ft_strncmp(op_str, "sa", 2))
		return (sa);
	else if (!ft_strncmp(op_str, "rra", 3))
		return (rra);
	else if (!ft_strncmp(op_str, "rrb", 3))
		return (rrb);
	else if (!ft_strncmp(op_str, "rrr", 3))
		return (rrr);
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
	else
		return (null_op);
}

void	call_operation(t_push_swap *data, t_operations op)
{
	if (op == pa)
		push_a(data);
	else if (op == pb)
		push_b(data);
	else if (op == rra)
		r_rotate_a(data);
	else if (op == rrb)
		r_rotate_b(data);
	else if (op == rrr)
		r_rotate_ab(data);
	else if (op == ra)
		rotate_a(data);
	else if (op == rb)
		rotate_b(data);
	else if (op == rr)
		rotate_ab(data);
	else if (op == sa)
		swap_a(data);
	else if (op == sb)
		swap_b(data);
	else if (op == ss)
		swap_ab(data);
	else
		data_error(data);
}

bool	is_correctly_sorted(t_push_swap *data)
{
	t_list	*reader;

	reader = data->operations_list;
	while (reader)
	{
		call_operation(data, (t_operations)(uintptr_t)reader->content);
		reader = reader->next;
	}
	return (is_sorted(data) && is_full(&data->stack_a));
}
