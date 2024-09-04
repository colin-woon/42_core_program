/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:47:03 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/05 02:04:48 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

void	push(t_stack *src, t_stack *dest);
void	push_a(t_push_swap *data);
void	push_b(t_push_swap *data);

void	push(t_stack *src, t_stack *dest)
{
	int	i_dest;

	if (is_full(dest))
		return ;
	i_dest = get_index_up(dest, dest->i_top);
	dest->buffer[i_dest] = src->buffer[src->i_top];
	dest->i_top = i_dest;
	src->buffer[src->i_top] = 0;
	src->i_top = get_index_down(src, src->i_top);
}

void	push_a(t_push_swap *data)
{
	push(&data->stack_b, &data->stack_a);
	if (data->write_mode)
		save_operation(data, pa);
}

void	push_b(t_push_swap *data)
{
	push(&data->stack_a, &data->stack_b);
	if (data->write_mode)
		save_operation(data, pb);
}
