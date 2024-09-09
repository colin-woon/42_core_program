/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validate_flags_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:30:49 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/09 19:52:14 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	validate_flags(t_push_swap *data, char **av, t_flag *flag);
int		process_flag(t_push_swap *data, char **av, int i, t_flag *flag);

void	validate_flags(t_push_swap *data, char **av, t_flag *flag)
{
	int	i;
	int	i_str;
	int	i_dash;
	int	i_flag;

	i = 1;
	i_dash = 0;
	i_flag = 0;
	while(av[i])
	{
		i_str = 0;
		while (av[i][i_str])
		{
			if (av[i][i_str] == '-')
				i_dash = i_str;
			if (av[i][i_str] == 'c')
			{
				i_flag = i_str;
				break ;
			}
			i_str++;
		}
		// ft_printf("i is %d\n", i);
		if (i_dash)
			data_error(data);
		else if (i_dash == 0 && i_flag)
		{
			if (i_flag == i_dash + 1 && !av[i][i_flag + 1])
			{
				flag->i_cflag = i;
				break ;
			}
			else
				data_error(data);
		}
		i++;
	}
	// ft_printf("i_cflag is %d\n", flag->i_cflag);
}

