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
void	get_index_dash_n_flag(char *av, int *i_dash, int *i_flag);

void	validate_flag(t_push_swap *data, char **av, t_flag *flag)
{
	int	i;

	i = 1;
	while (av[i])
	{
		get_index_dash_n_flag(av[i], &flag->i_dash, &flag->index);
		if (flag->i_dash)
			data_error(data);
		else if (flag->i_dash == 0 && flag->index)
		{
			if (flag->index == flag->i_dash + 1 && !av[i][flag->index + 1])
			{
				flag->i_vflag = i;
				break ;
			}
			else
				data_error(data);
		}
		i++;
	}
}

void	get_index_dash_n_flag(char *av, int *i_dash, int *i_flag)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '-')
			*i_dash = i;
		if (av[i] == 'v')
		{
			*i_flag = i;
			break ;
		}
		i++;
	}
}
