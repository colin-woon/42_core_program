/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:33:54 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/04 01:38:19 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main (int ac, char **av)
{
	t_push_swap	data;

	initialize_data(&data, ac, av, false);
	if (data.stack_a.size == 0)
		exit(EXIT_SUCCESS);
	get_operations_list(&data);
}

void	get_operations_list(t_push_swap *data)
{

}
