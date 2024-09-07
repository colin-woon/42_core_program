/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:53:20 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/08 01:57:42 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
void	init_flags(int ac, t_flag *flag);
void	check_flags(int ac, char **av, t_flag *flag, t_push_swap *data);
char	**get_digits_n_stack_size(int ac, char **av, int *stack_size, t_flag flag);

void	init_flags(int ac, t_flag *flag)
{
	flag->is_colour = false;
	flag->is_show_stack = false;
	flag->write_mode = false;
	flag->num_start = 1;
	flag->num_end = ac - 1;
}

void	check_flags(int ac, char **av, t_flag *flag, t_push_swap *data)
{
	int	i_cflag;
	int	i;

	i = 1;
	i_cflag = 0;
	while(av[i])
	{
		if (!ft_strncmp(av[i], "-c", 2))
		{
			i_cflag = i;
			break ;
		}
		i++;
	}
	if (i_cflag)
	{
		if (i_cflag != 1 && i_cflag != ac - 1)
			return data_error(data) ;
		else if (i_cflag == 1)
			flag->num_start++;
		else if (i_cflag == ac - 1)
			flag->num_end--;
		flag->is_colour = true;
	}
}

char	**get_digits_n_stack_size(int ac, char **av, int *stack_size, t_flag flag)
{
	char	**digits;

	if (ac > 1 && ac <= 3)
	{
		digits = ft_split(av[flag.num_start], ' ');
		*stack_size = 0;
		while (digits[*stack_size])
			(*stack_size)++;
	}
	else
	{
		*stack_size = flag.num_end;
		// ft_printf("in av %s\n",av[1]);
		digits = &av[flag.num_start];
	}
	return (digits);
}
