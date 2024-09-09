/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:33:54 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/09 20:59:00 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_output(t_push_swap *data, t_flag *flag);

int	main(int ac, char **av)
{
	t_push_swap	data;
	t_flag		flag;

	init_flags(ac, &flag);
	check_flags(ac, av, &flag, &data);
	// ft_printf("s %d, e %d\n", flag.num_start, flag.num_end);
	init_and_validate_data_bonus(&data, ac, av, flag);
	if (data.stack_a.size == 0)
		exit(EXIT_SUCCESS);
	get_operations_list(&data);
	// print_operations(data.operations_list);
	check_output(&data, &flag);
	free_data(&data);
	exit(EXIT_SUCCESS);
}

void	check_output(t_push_swap *data, t_flag *flag)
{
	if (is_correctly_sorted(data))
	{
		if (flag->is_colour)
			ft_printf(COLOURED_OK);
		else
			ft_printf("OK\n");
	}
	else
	{
		if (flag->is_colour)
			ft_printf(COLOURED_KO);
		else
			ft_printf("KO\n");
	}
}
