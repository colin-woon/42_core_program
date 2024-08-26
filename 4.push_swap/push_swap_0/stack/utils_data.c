/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:09:04 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/26 21:18:22 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	data_error(t_push_swap *data);
void	free_data(t_push_swap *data);

void	data_error(t_push_swap *data)
{
	free_data(data);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
void	free_data(t_push_swap *data)
{
	if (data->stack_a.buffer)
		free(data->stack_a.buffer);
	if (data->stack_b.buffer)
		free(data->stack_b.buffer);
	if (data->operations_list)
		ft_lstclear(&data->operations_list, NULL);
}
