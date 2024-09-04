/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:28:08 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/04 20:25:20 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap	data;

	init_and_validate_data(&data, ac, av, true);
	sort(&data);
	print_operations(data.operations_list);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
