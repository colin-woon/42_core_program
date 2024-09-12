/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort_optimization.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:43:56 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/12 18:53:02 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		post_sort_optimization(t_push_swap *data);
static void	polish_operations_list(t_list *ops_list, t_list **optimized_list);

void	post_sort_optimization(t_push_swap *data)
{
	t_list	*optimized_list;

	if (data->operations_list == NULL)
		return ;
	optimized_list = NULL;
	polish_operations_list(data->operations_list, &optimized_list);
	if (is_valid_list(optimized_list))
	{
		ft_lstclear(&data->operations_list, NULL);
		data->operations_list = optimized_list;
	}
	else
	{
		ft_lstclear(&optimized_list, NULL);
		data_error(data);
	}
}

static void	polish_operations_list(t_list *ops_list, t_list **optimized_list)
{
	t_list			*reader;
	t_operations	double_operation;

	reader = ops_list;
	while (reader && reader->next)
	{
		double_operation = get_double_operation(op_from(reader), \
		op_from(reader->next));
		if (double_operation)
		{
			save_optimized_operation(optimized_list, double_operation);
			reader = reader->next->next;
		}
		else if (is_useless_operations(op_from(reader), op_from(reader->next)))
			reader = reader->next->next;
		else
		{
			save_optimized_operation(optimized_list, \
			(t_operations)(uintptr_t)reader->content);
			reader = reader->next;
		}
	}
	if (reader)
		save_optimized_operation(optimized_list, \
		(t_operations)(uintptr_t)reader->content);
}
