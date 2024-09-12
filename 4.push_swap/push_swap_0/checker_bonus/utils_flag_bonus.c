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
void	get_stack_size(char **digits, int *stack_size);

void	init_flag(int ac, t_flag *flag)
{
	flag->is_display_stack = false;
	flag->is_colour = true;
	flag->write_mode = false;
	flag->found_at_end = false;
	flag->found_v = false;
	flag->found_c = false;
	flag->num_start = 1;
	flag->num_end = ac - 1;
	flag->i_flag = 0;
	flag->i_dash = 0;
	flag->index = 0;
}

void	check_flag(int ac, char **av, t_flag *flag, t_push_swap *data)
{
	validate_flag(data, av, flag);
	if (flag->i_flag)
	{
		if (flag->i_flag != 1 \
		&& flag->i_flag != ac - 1 && flag->i_flag != ac - 2)
			return (data_error(data));
		else if (flag->i_flag == 1)
			flag->num_start++;
		else if (flag->i_flag == ac - 1)
		{
			flag->num_end--;
			flag->found_at_end = true;
		}
		else if (flag->i_flag == ac - 2)
		{
			flag->num_end = flag->num_end - 2;
			flag->found_at_end = true;
		}
		if (flag->found_v)
			flag->is_display_stack = true;
		else if (flag->found_c)
			flag->is_colour = false;
	}
}

char	**get_digits_n_stack_size(int ac, char **av, int *stack_size, \
		t_flag flag)
{
	char	**digits;

	digits = NULL;
	if (ac > 1 && ac <= 3)
	{
		if (ac == 2)
			digits = ft_split(av[1], ' ');
		else if (ac == 3)
		{
			if (!flag.is_colour || flag.is_display_stack)
				digits = ft_split(av[flag.num_start], ' ');
			else
				digits = &av[flag.num_start];
		}
		get_stack_size(digits, stack_size);
	}
	else
	{
		if (!flag.found_at_end && (flag.is_display_stack || !flag.is_colour))
			*stack_size = flag.num_end - 1;
		else
			*stack_size = flag.num_end;
		digits = &av[flag.num_start];
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

void	get_stack_size(char **digits, int *stack_size)
{
	while (digits[*stack_size])
		(*stack_size)++;
}
