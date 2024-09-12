/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_way_quick_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:01:53 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/12 18:53:15 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		three_way_quick_sort(t_push_swap *data);
static void	recursive_chunk_sort(t_push_swap *data, t_chunk *chunk_to_sort);
static void	split_chunk(t_push_swap *data, t_chunk *chunk, t_split_dest *dest);
static void	sort_one_chunk(t_push_swap *data, t_chunk *chunk_to_sort);
static void	sort_two_chunk(t_push_swap *data, t_chunk *chunk_to_sort);

void	three_way_quick_sort(t_push_swap *data)
{
	t_chunk	head_chunk;

	head_chunk.area = TOP_A;
	head_chunk.size = data->stack_a.size;
	recursive_chunk_sort(data, &head_chunk);
}

static void	recursive_chunk_sort(t_push_swap *data, t_chunk *chunk_to_sort)
{
	t_split_dest	dest;

	if (chunk_to_sort->area == BOTTOM_B \
	&& get_current_size(&data->stack_b) == chunk_to_sort->size)
		chunk_to_sort->area = TOP_B;
	else if (chunk_to_sort->area == BOTTOM_A \
	&& get_current_size(&data->stack_a) == chunk_to_sort->size)
		chunk_to_sort->area = TOP_A;
	if (chunk_to_sort->size <= 2)
	{
		if (chunk_to_sort->size == 2)
			sort_two_chunk(data, chunk_to_sort);
		if (chunk_to_sort->size == 1)
			sort_one_chunk(data, chunk_to_sort);
		return ;
	}
	split_chunk(data, chunk_to_sort, &dest);
	recursive_chunk_sort(data, &dest.max);
	recursive_chunk_sort(data, &dest.mid);
	recursive_chunk_sort(data, &dest.min);
}

static void	split_chunk(t_push_swap *data, t_chunk *chunk, t_split_dest *dest)
{
	t_qsort_vars	vars;

	set_split_areas(chunk->area, dest);
	set_pivots(dest, chunk, &vars.pivot_upper, &vars.pivot_lower);
	vars.max_value = get_chunk_value(data, chunk->area, chunk->size, true);
	vars.upper_threshold = vars.max_value - vars.pivot_lower;
	vars.lower_threshold = vars.max_value - vars.pivot_upper;
	while (chunk->size--)
	{
		vars.next_value = get_chunk_value(data, chunk->area, 1, false);
		if (vars.next_value > vars.upper_threshold)
			dest->max.size += move_from_to(data, chunk->area, dest->max.area);
		else if (vars.next_value > vars.lower_threshold)
			dest->mid.size += move_from_to(data, chunk->area, dest->mid.area);
		else
			dest->min.size += move_from_to(data, chunk->area, dest->min.area);
	}
}

static void	sort_one_chunk(t_push_swap *data, t_chunk *chunk_to_sort)
{
	if (chunk_to_sort->area == BOTTOM_A \
	|| chunk_to_sort->area == BOTTOM_B \
	|| chunk_to_sort->area == TOP_B)
		move_from_to(data, chunk_to_sort->area, TOP_A);
	chunk_to_sort->size -= 1;
}

static void	sort_two_chunk(t_push_swap *data, t_chunk *chunk_to_sort)
{
	int	top;
	int	btm;

	if (chunk_to_sort->area == BOTTOM_A \
	|| chunk_to_sort->area == BOTTOM_B \
	|| chunk_to_sort->area == TOP_B)
	{
		move_from_to(data, chunk_to_sort->area, TOP_A);
		move_from_to(data, chunk_to_sort->area, TOP_A);
	}
	top = get_stack_value(&data->stack_a, 1);
	btm = get_stack_value(&data->stack_a, 2);
	if (top > btm)
		swap_a(data);
	chunk_to_sort->size -= 2;
}
