/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:55:38 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/07 12:52:05 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

void			save_operation(t_push_swap *data, t_operations op);
t_operations	op_from(t_list *node);
const char		*op_to_string(t_operations op);
void			print_operations(t_list *head);

void	save_operation(t_push_swap *data, t_operations op)
{
	t_list	*new_op;

	new_op = ft_lstnew((void *)(uintptr_t) op);
	if (new_op == NULL)
		data_error(data);
	ft_lstadd_back(&data->operations_list, new_op);
}

t_operations	op_from(t_list *node)
{
	return ((t_operations)(uintptr_t) node->content);
}

const char	*op_to_string(t_operations op)
{
	static const char	*strings[12];

	strings[0] = "null_op";
	strings[1] = "pa";
	strings[2] = "pb";
	strings[3] = "ra";
	strings[4] = "rb";
	strings[5] = "rr";
	strings[6] = "rra";
	strings[7] = "rrb";
	strings[8] = "rrr";
	strings[9] = "sa";
	strings[10] = "sb";
	strings[11] = "ss";
	return (strings[op]);
}

void	print_operations(t_list *head)
{
	t_list	*operations;

	operations = head;
	while (operations)
	{
		ft_printf("%s\n", op_to_string(op_from(operations)));
		operations = operations->next;
	}
}
