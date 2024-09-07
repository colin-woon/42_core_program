/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:33:54 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/08 01:10:56 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	t_push_swap	data;
	t_flag		flag;

	init_flags(ac, &flag);
	check_flags(ac, av, &flag, &data);
	ft_printf("s %d, e %d\n", flag.num_start, flag.num_end);
	init_and_validate_data_bonus(&data, ac, av, flag);
	if (data.stack_a.size == 0)
		exit(EXIT_SUCCESS);
	get_operations_list(&data);
	print_operations(data.operations_list);
	if (is_correctly_sorted(&data))
		flag.is_colour ? ft_printf("\033[1;32mOK\033[0m\n") : ft_printf("OK\n");  // Green for OK
	else
		flag.is_colour ? ft_printf("\033[1;31mKO\033[0m\n") : ft_printf("KO\n");
	free_data(&data);
	exit(EXIT_SUCCESS);
}


