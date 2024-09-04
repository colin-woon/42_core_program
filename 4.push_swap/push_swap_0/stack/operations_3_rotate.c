/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:06:40 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/04 13:42:15 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

void	rotate(t_stack *stack);
void	rotate_a(t_push_swap *data);
void	rotate_b(t_push_swap *data);
void	rotate_ab(t_push_swap *data);

void	rotate(t_stack *stack)
{
	if (is_full(stack))
	{
		stack->i_bottom = stack->i_top;
		stack->i_top = get_index_down(stack, stack->i_top);
	}
	else
	{
		stack->i_bottom = get_index_down(stack, stack->i_bottom);
		stack->buffer[stack->i_bottom] = stack->buffer[stack->i_top];
		stack->buffer[stack->i_top] = 0;
		stack->i_top = get_index_down(stack, stack->i_top);
	}
}

void	rotate_a(t_push_swap *data)
{
	rotate(&data->stack_a);
	if (data->write_mode)
		save_operation(data, ra);
}

void	rotate_b(t_push_swap *data)
{
	rotate(&data->stack_b);
	if (data->write_mode)
		save_operation(data, rb);
}

void	rotate_ab(t_push_swap *data)
{
	rotate(&data->stack_a);
	rotate(&data->stack_b);
	if (data->write_mode)
		save_operation(data, rr);
}
