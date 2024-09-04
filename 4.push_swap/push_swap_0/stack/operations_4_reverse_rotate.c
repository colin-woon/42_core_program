/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_4_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:23:37 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/04 13:42:22 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

void	r_rotate(t_stack *stack);
void	r_rotate_a(t_push_swap *data);
void	r_rotate_b(t_push_swap *data);
void	r_rotate_ab(t_push_swap *data);

void	r_rotate(t_stack *stack)
{
	if (is_full(stack))
	{
		stack->i_top = stack->i_bottom;
		stack->i_bottom = get_index_up(stack, stack->i_bottom);
	}
	else
	{
		stack->i_top = get_index_up(stack, stack->i_top);
		stack->buffer[stack->i_top] = stack->buffer[stack->i_bottom];
		stack->buffer[stack->i_bottom] = 0;
		stack->i_bottom = get_index_up(stack, stack->i_bottom);
	}
}

void	r_rotate_a(t_push_swap *data)
{
	r_rotate(&data->stack_a);
	if (data->write_mode)
		save_operation(data, rra);
}

void	r_rotate_b(t_push_swap *data)
{
	r_rotate(&data->stack_b);
	if (data->write_mode)
		save_operation(data, rrb);
}

void	r_rotate_ab(t_push_swap *data)
{
	r_rotate(&data->stack_a);
	r_rotate(&data->stack_b);
	if (data->write_mode)
		save_operation(data, rrr);
}
