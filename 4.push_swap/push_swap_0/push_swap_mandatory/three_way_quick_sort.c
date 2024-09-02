/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_way_quick_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:01:53 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/02 21:15:15 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_way_quick_sort(t_push_swap *data);
void	recursive_chunk_sort(t_push_swap *data, t_chunk *chunk_to_sort);
void	split_chunk(t_push_swap *data, t_chunk *chunk, t_split_dest *dest);
void	sort_one(t_push_swap *data, t_chunk *chunk_to_sort);

void	three_way_quick_sort(t_push_swap *data)
{
	t_chunk	head_chunk;

	head_chunk.area = TOP_A;
	head_chunk.size = data->stack_a.size;
	recursive_chunk_sort(data, &head_chunk);
}

void	recursive_chunk_sort(t_push_swap *data, t_chunk *chunk_to_sort)
{
	t_split_dest	dest;

	if (chunk_to_sort->size <= 1)
	{
		sort_one(data, chunk_to_sort);
		return ;
	}
	split_chunk(data, chunk_to_sort, &dest);
	recursive_chunk_sort(data, &dest.max);
	recursive_chunk_sort(data, &dest.mid);
	recursive_chunk_sort(data, &dest.min);
}

void	split_chunk(t_push_swap *data, t_chunk *chunk, t_split_dest *dest)
{
	int	pivot_upper;
	int	pivot_lower;
	int	next_value;
	int	max_value;
	int	lower_threshold;
	int	upper_threshold;

	set_split_areas(chunk->area, dest);
	set_pivots(dest, chunk->area, chunk->size, &pivot_upper, &pivot_lower);
	max_value = get_chunk_value(data, chunk->area, chunk->size, true);
	upper_threshold = max_value - pivot_lower;
	lower_threshold = max_value - pivot_upper;
	// ft_printf("%d\n", dest->max);
	// ft_printf("%d\n", dest->mid);
	// ft_printf("%d\n", dest->min);
	// ft_printf("%d\n", data->write_mode);
	while(chunk->size--)
	{
		next_value = get_chunk_value(data, chunk->area, 1, false);
		// 	ft_printf("max_value: %d\n", max_value);
		// ft_printf("pivot_upper: %d\n", pivot_lower);
		// ft_printf("next_value: %d\n", next_value);
		if (next_value > upper_threshold)
			dest->max.size += move_from_to(data, chunk->area, dest->max.area);
		else if (next_value > lower_threshold)
			dest->mid.size += move_from_to(data, chunk->area, dest->mid.area);
		else
			dest->min.size += move_from_to(data, chunk->area, dest->min.area);
	}
}

void	sort_one(t_push_swap *data, t_chunk *chunk_to_sort)
{
	if(chunk_to_sort->area == BOTTOM_A \
	|| chunk_to_sort->area == BOTTOM_B \
	|| chunk_to_sort->area == TOP_B)
		move_from_to(data, chunk_to_sort->area, TOP_A);
	chunk_to_sort->size -= 1;
}
