/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:05:12 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/05 02:46:19 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_push_swap *data);
void	sort_three(t_push_swap *data);
void	sort_five(t_push_swap *data);

void	sort(t_push_swap *data)
{
	if (data->stack_a.size <= 1 || is_sorted(data))
		return ;
	else if (data->stack_a.size == 3)
		sort_three(data);
	else if (data->stack_a.size == 5)
		sort_five(data);
	else
		three_way_quick_sort(data);
	post_sort_optimization(data);
}

void	sort_three(t_push_swap *data)
{
	int	top;
	int	mid;
	int	btm;

	top = get_stack_value(&data->stack_a, 1);
	mid = get_stack_value(&data->stack_a, 2);
	btm = get_stack_value(&data->stack_a, 3);
	if (top < mid && mid > btm && btm > top)
	{
		r_rotate_a(data);
		swap_a(data);
	}
	else if (top > mid && mid < btm && btm > top)
		swap_a(data);
	else if (top < mid && mid > btm && btm < top)
		r_rotate_a(data);
	else if (top > mid && mid < btm && btm < top)
		rotate_a(data);
	else if (top > mid && mid > btm && btm < top)
	{
		swap_a(data);
		r_rotate_a(data);
	}
}

void	sort_five(t_push_swap *data)
{
	int	first_a;
	int	first_b;
	int	second_b;

	first_a = 0;
	while (get_current_size(&data->stack_a) > 3)
	{
		first_a = get_stack_value(&data->stack_a, 1);
		if (first_a == 1 || first_a == 2)
			push_b(data);
		else
			rotate_a(data);
	}
	first_b = get_stack_value(&data->stack_b, 1);
	second_b = get_stack_value(&data->stack_b, 2);
	if (first_b < second_b)
		swap_b(data);
	sort_three(data);
	push_a(data);
	push_a(data);
}
