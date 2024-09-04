/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:13:27 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/04 13:41:51 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

void		swap(t_stack *stack);
void		swap_a(t_push_swap *data);
void		swap_b(t_push_swap *data);
void		swap_ab(t_push_swap *data);

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->buffer[get_index_down(stack, stack->i_top)] == 0)
		return ;
	temp = stack->buffer[get_index_down(stack, stack->i_top)];
	stack->buffer[get_index_down(stack, stack->i_top)] \
	= stack->buffer[stack->i_top];
	stack->buffer[stack->i_top] = temp;
}

void	swap_a(t_push_swap *data)
{
	swap(&data->stack_a);
	if (data->write_mode)
		save_operation(data, sa);
}

void	swap_b(t_push_swap *data)
{
	swap(&data->stack_b);
	if (data->write_mode)
		save_operation(data, sb);
}

void	swap_ab(t_push_swap *data)
{
	swap(&data->stack_a);
	swap(&data->stack_b);
	if (data->write_mode)
		save_operation(data, ss);
}
