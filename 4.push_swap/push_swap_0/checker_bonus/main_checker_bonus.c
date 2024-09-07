/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:33:54 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/07 15:23:33 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	t_push_swap	data;

	init_and_validate_data(&data, ac, av, false);
	if (data.stack_a.size == 0)
		exit(EXIT_SUCCESS);
	get_operations_list(&data);
	if (is_correctly_sorted(&data))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_data(&data);
	exit(EXIT_SUCCESS);
}
