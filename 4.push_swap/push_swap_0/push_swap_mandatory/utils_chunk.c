/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:56:24 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/04 13:54:38 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_split_areas(t_area current_area, t_split_dest *dest);
void	set_pivots(t_split_dest *dest, t_chunk *chunk, int *pivot_upper, \
		int *pivot_lower);
int		get_chunk_value(t_push_swap *data, t_area current_area, int n, \
bool is_finding_max);
t_stack	*get_stack_at(t_push_swap *data, t_area current_area);
int		get_current_index(t_area current_area, t_stack *stack);

void	set_split_areas(t_area current_area, t_split_dest *dest)
{
	if (current_area == TOP_A)
	{
		dest->max.area = BOTTOM_A;
		dest->mid.area = TOP_B;
		dest->min.area = BOTTOM_B;
	}
	else if (current_area == BOTTOM_A)
	{
		dest->max.area = TOP_A;
		dest->mid.area = TOP_B;
		dest->min.area = BOTTOM_B;
	}
	else if (current_area == TOP_B)
	{
		dest->max.area = TOP_A;
		dest->mid.area = BOTTOM_A;
		dest->min.area = BOTTOM_B;
	}
	else if (current_area == BOTTOM_B)
	{
		dest->max.area = TOP_A;
		dest->mid.area = BOTTOM_A;
		dest->min.area = TOP_B;
	}
}

void	set_pivots(t_split_dest *dest, t_chunk *chunk, int *pivot_upper, \
		int *pivot_lower)
{
	t_area	current_area;
	int		split_size;

	current_area = chunk->area;
	split_size = chunk->size;
	dest->max.size = 0;
	dest->mid.size = 0;
	dest->min.size = 0;
	*pivot_lower = split_size / 3;
	if (current_area == TOP_A || current_area == BOTTOM_A)
	{
		*pivot_upper = 2 * split_size / 3;
		if (split_size < 15)
			*pivot_upper = split_size;
	}
	else if (current_area == TOP_B || current_area == BOTTOM_B)
	{
		*pivot_upper = split_size / 2;
		if (current_area == BOTTOM_B && split_size < 8)
			*pivot_lower = *pivot_upper;
	}
}

int	get_chunk_value(t_push_swap *data, t_area current_area, int size, \
	bool is_finding_max)
{
	t_stack	*stack;
	int		i;
	int		max_value;

	max_value = 0;
	stack = get_stack_at(data, current_area);
	i = get_current_index(current_area, stack);
	if (!is_finding_max)
		--size;
	while (size--)
	{
		if (is_finding_max && stack->buffer[i] > max_value)
			max_value = stack->buffer[i];
		if (current_area == TOP_A || current_area == TOP_B)
			i = get_index_down(stack, i);
		else if (current_area == BOTTOM_A || current_area == BOTTOM_B)
			i = get_index_up(stack, i);
	}
	if (!is_finding_max)
		return (stack->buffer[i]);
	else
		return (max_value);
}

t_stack	*get_stack_at(t_push_swap *data, t_area current_area)
{
	if (current_area == TOP_A || current_area == BOTTOM_A)
		return (&data->stack_a);
	else
		return (&data->stack_b);
}

int	get_current_index(t_area current_area, t_stack *stack)
{
	if (current_area == TOP_A || current_area == TOP_B)
		return (stack->i_top);
	else
		return (stack->i_bottom);
}
