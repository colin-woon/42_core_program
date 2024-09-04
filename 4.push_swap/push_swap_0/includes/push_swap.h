/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:12:49 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/05 02:49:58 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

typedef struct s_push_swap
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_list	*operations_list;
	bool	write_mode;
}	t_push_swap;

typedef enum e_area
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}	t_area;

typedef struct s_chunk
{
	enum e_area	area;
	int			size;
}	t_chunk;

typedef struct s_split_dest
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}	t_split_dest;

typedef struct s_qsort_vars
{
	int	pivot_upper;
	int	pivot_lower;
	int	next_value;
	int	max_value;
	int	lower_threshold;
	int	upper_threshold;
}	t_qsort_vars;

// Utils Data
void	data_error(t_push_swap *data);
void	free_data(t_push_swap *data);
void	init_and_validate_data(t_push_swap *data, int ac, char **av, \
		bool write_mode);
void	initialize_stack(t_push_swap *data, t_stack *stack, int stack_size);
void	fill_stack(t_push_swap *data, t_stack *stack, \
int stack_size, char **digits);

// Utils Validate
bool	validate_numbers(char *digits);
void	finding_duplicates(t_push_swap *data, int *numbers, int stack_size);
void	ranking_numbers(int *numbers, int *stack_a, int size);
bool	is_sorted(t_push_swap *data);

// Utils Chunk
void	set_split_areas(t_area current_area, t_split_dest *dest);
void	set_pivots(t_split_dest *dest, t_chunk *chunk, int *pivot_upper, \
		int *pivot_lower);
int		get_chunk_value(t_push_swap *data, t_area current_area, int n, \
		bool is_finding_max);
t_stack	*get_stack_at(t_push_swap *data, t_area current_area);

// Operations Chunk
int		move_from_to(t_push_swap *data, t_area from, t_area to);

// Sort Basic
void	sort(t_push_swap *data);
void	sort_three_basic(t_push_swap *data);
void	sort_five(t_push_swap *data);

// Three-way Quick Sort
void	three_way_quick_sort(t_push_swap *data);

// Optimization
void	post_sort_optimization(t_push_swap *data);

#endif
