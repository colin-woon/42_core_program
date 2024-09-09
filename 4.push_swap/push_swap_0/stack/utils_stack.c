/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:19:28 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/09 15:31:37 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int			get_current_size(t_stack *stack);
bool		is_full(t_stack *stack);
int			get_index_up(t_stack *stack, int index);
int			get_index_down(t_stack *stack, int index);
int			get_stack_value(t_stack *stack, int nth_value);

int	get_current_size(t_stack *stack)
{
	if (stack->i_top == stack->i_bottom && stack->buffer[stack->i_top] == 0)
		return (0);
	else if (stack->i_top > stack->i_bottom)
		return (stack->size - stack->i_top + stack->i_bottom + 1);
	else
		return (stack->i_bottom - stack->i_top + 1);
}

bool	is_full(t_stack *stack)
{
	return (stack->size == get_current_size(stack));
}

int	get_index_up(t_stack *stack, int index)
{
	int	stack_bottom;

	stack_bottom = stack->size - 1;
	if (get_current_size(stack) == 0)
		return (index);
	else if (index == 0)
		return (stack_bottom);
	else
		return (index - 1);
}

int	get_index_down(t_stack *stack, int index)
{
	int	stack_top;

	stack_top = 0;
	if (get_current_size(stack) == 0)
		return (index);
	else if (index == stack->size - 1)
		return (stack_top);
	else
		return (index + 1);
}

int	get_stack_value(t_stack *stack, int nth_value)
{
	int	i_value;

	i_value = stack->i_top;
	while (--nth_value > 0)
		i_value = get_index_down(stack, i_value);
	return (stack->buffer[i_value]);
}
