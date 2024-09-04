/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_optimization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:54:26 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/04 13:18:59 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_operations	get_double_operation(t_operations now_op, t_operations next_op);
bool			is_useless_operations(t_operations now_op, \
t_operations next_op);
bool			is_valid_list(t_list *optimized);
void			save_optimized_operation(t_list **optimized, \
t_operations optimized_op);

t_operations	get_double_operation(t_operations now_op, t_operations next_op)
{
	if ((now_op == sa && next_op == sb) || (now_op == sb && next_op == sa))
		return (ss);
	else if ((now_op == ra && next_op == rb) || (now_op == rb && next_op == ra))
		return (rr);
	else if ((now_op == rra && next_op == rrb) \
	|| (now_op == rrb && next_op == rra))
		return (rrr);
	else
		return (null_op);
}

bool	is_useless_operations(t_operations now_op, t_operations next_op)
{
	if ((now_op == pa && next_op == pb) || (now_op == pb && next_op == pa))
		return (true);
	else if ((now_op == ra && next_op == rra) \
	|| (now_op == rra && next_op == ra))
		return (true);
	else if ((now_op == rb && next_op == rrb) \
	|| (now_op == rrb && next_op == rb))
		return (true);
	else if ((now_op == sa && next_op == sa) \
	|| (now_op == sb && next_op == sb))
		return (true);
	else
		return (false);
}

bool	is_valid_list(t_list *optimized)
{
	while (optimized && optimized->next)
	{
		if (optimized->content == NULL)
			return (false);
		optimized = optimized->next;
	}
	return (true);
}

void	save_optimized_operation(t_list **optimized, t_operations optimized_op)
{
	t_list	*new_op;

	new_op = ft_lstnew((void *)(uintptr_t) optimized_op);
	if (new_op == NULL)
		return ;
	ft_lstadd_back(optimized, new_op);
}
