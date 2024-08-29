/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:28:08 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 17:55:57 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap	data;

	initialize_data(&data, ac, av, true);
	sort(&data);
	print_operations(data.operations_list);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
