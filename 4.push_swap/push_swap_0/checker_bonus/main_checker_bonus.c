/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:33:54 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/12 19:01:57 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	check_output(t_push_swap *data, t_flag *flag);
static void	init_data_state(t_push_swap *data);

int	main(int ac, char **av)
{
	t_push_swap	data;
	t_flag		flag;

	init_data_state(&data);
	init_flag(ac, &flag);
	check_flag(ac, av, &flag, &data);
	init_and_validate_data_bonus(&data, ac, av, flag);
	if (data.stack_a.size == 0)
		exit(EXIT_SUCCESS);
	get_operations_list(&data);
	check_output(&data, &flag);
	free_data(&data);
	exit(EXIT_SUCCESS);
}

static void	check_output(t_push_swap *data, t_flag *flag)
{
	if (is_correctly_sorted(data, flag))
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

static void	init_data_state(t_push_swap *data)
{
	data->stack_a.buffer = NULL;
	data->stack_a.i_top = 0;
	data->stack_a.i_bottom = 0;
	data->stack_a.size = 0;
	data->stack_b.buffer = NULL;
	data->stack_b.i_top = 0;
	data->stack_b.i_bottom = 0;
	data->stack_b.size = 0;
	data->operations_list = NULL;
	data->write_mode = false;
}
