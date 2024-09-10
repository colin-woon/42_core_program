/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validate_flag_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:30:49 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/09 21:44:41 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	validate_flag(t_push_swap *data, char **av, t_flag *flag);
void	get_index_dash_n_flag(char *av, t_flag *flag);

void	validate_flag(t_push_swap *data, char **av, t_flag *flag)
{
	int	i;

	i = 1;
	while (av[i])
	{
		get_index_dash_n_flag(av[i], flag);
		if (flag->i_dash)
			data_error(data);
		else if (flag->found_c && flag->found_v)
			data_error(data);
		else if (flag->i_dash == 0 && flag->index)
		{
			if (flag->index == flag->i_dash + 1 && !av[i][flag->index + 1])
			{
				flag->i_flag = i;
				break ;
			}
			else
				data_error(data);
		}
		i++;
	}
}

void	get_index_dash_n_flag(char *av, t_flag *flag)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '-')
			flag->i_dash = i;
		if (av[i] == 'v')
		{
			flag->index = i;
			flag->found_v = true;
		}
		if (av[i] == 'c')
		{
			flag->index = i;
			flag->found_c = true;
		}
		i++;
	}
}
