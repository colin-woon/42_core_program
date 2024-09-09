/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:09:08 by ugerkens          #+#    #+#             */
/*   Updated: 2024/09/09 20:36:06 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

bool	validate_numbers_bonus(char *digits);
void	finding_duplicates(t_push_swap *data, int *numbers, int stack_size);
void	ranking_numbers(int *numbers, int *stack_a, int size);
bool	is_sorted(t_push_swap *data);

bool	validate_numbers_bonus(char *digits)
{
	long long	num;
	int			sign;

	sign = 1;
	if (*digits == '\0')
		return (false);
	if (*digits == '-' || *digits == '+')
	{
		if (*digits == '-')
			sign = -1;
		digits++;
		if (*digits == '\0')
			return (false);
	}
	num = 0;
	while (*digits)
	{
		// ft_printf("validate digits is %d\n", (*digits));
		if (!ft_isdigit(*digits))
			return (false);
		num = num * 10 + (*digits - '0');
		if (((sign == 1 && num > INT_MAX) || (sign == -1 && - num < INT_MIN)))
			return (false);
		digits++;
	}
	return (true);
}

void	finding_duplicates(t_push_swap *data, int *numbers, int stack_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_size)
	{
		j = i + 1;
		while (j < stack_size)
		{
			if (numbers[i] == numbers[j])
			{
				free(numbers);
				data_error(data);
			}
			j++;
		}
		i++;
	}
}

// Ascending order, Rank increases when number is larger than others
void	ranking_numbers(int *numbers, int *stack_a, int size)
{
	int	i;
	int	compare_i;
	int	rank;

	i = 0;
	// ft_printf("size is %d\n", size);
	while (i < size)
	{
		compare_i = 0;
		rank = 0;
		while (compare_i < size)
		{
			if (numbers[compare_i] <= numbers[i])
				rank++;
			compare_i++;
		}
		// ft_printf("compare_i is %d\n", compare_i);
		// ft_printf("i is %d\n", i);
		// ft_printf("numbers[compare_i] is %d\n", numbers[i]);
		// ft_printf("stack_a[i] is %d\n", stack_a[i]);
		stack_a[i] = rank;
		i++;
	}
}

bool	is_sorted(t_push_swap *data)
{
	int	i;
	int	rank;

	i = data->stack_a.i_top;
	rank = 1;
	// ft_printf("stack i_top is%d\n", data->stack_a.i_top);
	while (rank <= data->stack_a.size)
	{
		// ft_printf("stack buffer i is%d\n", data->stack_a.buffer[i]);
		// ft_printf("rank is%d\n", rank);
		if (data->stack_a.buffer[i] != rank)
		{
			// ft_printf("is_sorted failed\n");
			return (false);
		}
		rank++;
		i = get_index_down(&data->stack_a, i);
	}
	return (true);
}
