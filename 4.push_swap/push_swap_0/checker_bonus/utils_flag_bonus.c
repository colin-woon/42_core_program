/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 23:53:20 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/09 21:44:20 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	init_flag(int ac, t_flag *flag);
void	check_flag(int ac, char **av, t_flag *flag, t_push_swap *data);
char	**get_digits_n_stack_size(int ac, char **av, int *stack_size, \
		t_flag flag);
void	print_stack(t_stack *stack, char a_or_b);

void	init_flag(int ac, t_flag *flag)
{
	flag->is_display_stack = false;
	flag->write_mode = false;
	flag->found_at_end = false;
	flag->num_start = 1;
	flag->num_end = ac - 1;
	flag->i_vflag = 0;
	flag->i_dash = 0;
	flag->index = 0;
}

void	check_flag(int ac, char **av, t_flag *flag, t_push_swap *data)
{
	validate_flag(data, av, flag);
	// ft_printf("flag->i_vflag is%d\n", flag->i_vflag);
	if (flag->i_vflag)
	{
		if (flag->i_vflag != 1 && flag->i_vflag != ac - 1)
			return (data_error(data));
		else if (flag->i_vflag == 1)
			flag->num_start++;
		else if (flag->i_vflag == ac - 1)
		{
			flag->num_end--;
			flag->found_at_end = true;
		}
		flag->is_display_stack = true;
	}
}

char	**get_digits_n_stack_size(int ac, char **av, int *stack_size, \
		t_flag flag)
{
	char	**digits;

	if (ac > 1 && ac <= 3)
	{
		// ft_printf("num_start is %d\n",flag.num_start);
		if (ac == 2)
			digits = ft_split(av[1], ' ');
		else
			digits = ft_split(av[flag.num_start], ' ');
		*stack_size = 0;
		while (digits[*stack_size])
		{
			// ft_printf("stack size is %d\n", (*stack_size));
			(*stack_size)++;
		}
	}
	else
	{
		// ft_printf("i_vflag is %d\n",flag.i_vflag);
		// ft_printf("num_start is %d\n",flag.num_start);
		// ft_printf("num_end is %d\n",flag.num_end);
		if (!flag.found_at_end && flag.is_display_stack)
			*stack_size = flag.num_end - 1;
		else
			*stack_size = flag.num_end;
		// ft_printf("stack size is %d\n", (*stack_size));
		// ft_printf("in av %s\n",av[1]);
		digits = &av[flag.num_start];
		// ft_printf("flag num_start is%d\n", flag.num_start);
	}
	return (digits);
}

void	print_stack(t_stack *stack, char a_or_b)
{
	int	i;
	int	size_count;

	i = (*stack).i_top;
	size_count = 1;
	ft_printf("Stack %c: [ ", a_or_b);
	while (size_count <= (*stack).size)
	{
		ft_printf("%d ", stack->buffer[i]);
		size_count++;
		i = get_index_down(stack, i);
	}
	ft_printf("]\n");
}
