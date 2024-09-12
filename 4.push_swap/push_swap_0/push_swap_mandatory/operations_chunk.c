/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_chunk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:27:58 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/12 18:52:55 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			move_from_to(t_push_swap *data, t_area from, t_area to);
static void	move_from_top_a(t_push_swap *data, t_area to);
static void	move_from_bottom_a(t_push_swap *data, t_area to);
static void	move_from_top_b(t_push_swap *data, t_area to);
static void	move_from_bottom_b(t_push_swap *data, t_area to);

int	move_from_to(t_push_swap *data, t_area from, t_area to)
{
	if (from == TOP_A)
		move_from_top_a(data, to);
	else if (from == BOTTOM_A)
		move_from_bottom_a(data, to);
	else if (from == TOP_B)
		move_from_top_b(data, to);
	else if (from == BOTTOM_B)
		move_from_bottom_b(data, to);
	return (1);
}

static void	move_from_top_a(t_push_swap *data, t_area to)
{
	if (to == BOTTOM_A)
		rotate_a(data);
	else if (to == TOP_B)
		push_b(data);
	else if (to == BOTTOM_B)
	{
		push_b(data);
		rotate_b(data);
	}
}

static void	move_from_bottom_a(t_push_swap *data, t_area to)
{
	if (to == TOP_A)
		r_rotate_a(data);
	else if (to == TOP_B)
	{
		r_rotate_a(data);
		push_b(data);
	}
	else if (to == BOTTOM_B)
	{
		r_rotate_a(data);
		push_b(data);
		rotate_b(data);
	}
}

static void	move_from_top_b(t_push_swap *data, t_area to)
{
	if (to == BOTTOM_B)
		rotate_b(data);
	else if (to == TOP_A)
		push_a(data);
	else if (to == BOTTOM_A)
	{
		push_a(data);
		rotate_a(data);
	}
}

static void	move_from_bottom_b(t_push_swap *data, t_area to)
{
	if (to == TOP_B)
		r_rotate_b(data);
	else if (to == TOP_A)
	{
		r_rotate_b(data);
		push_a(data);
	}
	else if (to == BOTTOM_A)
	{
		r_rotate_b(data);
		push_a(data);
		rotate_a(data);
	}
}
