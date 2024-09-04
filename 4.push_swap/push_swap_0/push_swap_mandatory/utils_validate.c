/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:09:08 by ugerkens          #+#    #+#             */
/*   Updated: 2024/09/05 02:39:56 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	validate_numbers(char *digits);
void	finding_duplicates(t_push_swap *data, int *numbers, int stack_size);
void	ranking_numbers(int *numbers, int *stack_a, int size);
bool	is_sorted(t_push_swap *data);

bool	validate_numbers(char *digits)
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
	while (rank <= data->stack_a.size)
	{
		if (data->stack_a.buffer[i] != rank)
			return (false);
		rank++;
		i = get_index_down(&data->stack_a, i);
	}
	return (true);
}
