/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:09:04 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/12 21:17:00 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_error(t_push_swap *data);
void	free_data(t_push_swap *data);
void	init_and_validate_data(t_push_swap *data, int ac, char **av, \
			bool write_mode);
void	initialize_stack(t_push_swap *data, t_stack *stack, int stack_size);
void	fill_stack(t_push_swap *data, t_stack *stack, \
		int stack_size, char **digits);

void	init_and_validate_data(t_push_swap *data, int ac, char **av, \
		bool write_mode)
{
	int		stack_size;
	char	**digits;

	if (ac == 2)
	{
		digits = ft_split(av[1], ' ');
		stack_size = 0;
		while (digits[stack_size])
			stack_size++;
	}
	else
	{
		stack_size = ac - 1;
		digits = ++av;
	}
	initialize_stack(data, &data->stack_a, stack_size);
	initialize_stack(data, &data->stack_b, stack_size);
	fill_stack(data, &data->stack_a, stack_size, digits);
	data->write_mode = write_mode;
	data->operations_list = NULL;
	if (ac == 2)
		ft_free_2d_array(digits);
}

void	initialize_stack(t_push_swap *data, t_stack *stack, int stack_size)
{
	int	buffer_size;

	buffer_size = sizeof(int) * stack_size;
	stack->buffer = malloc(buffer_size);
	if (stack->buffer == NULL)
		return (data_error(data));
	stack->i_top = 0;
	stack->i_bottom = 0;
	stack->size = stack_size;
	ft_memset(stack->buffer, 0, buffer_size);
}

void	fill_stack(t_push_swap *data, t_stack *stack, \
int stack_size, char **digits)
{
	int	*numbers;
	int	i;

	i = 0;
	numbers = malloc(sizeof(int) * stack_size);
	if (numbers == NULL)
		data_error(data);
	while (digits[i])
	{
		if (validate_numbers(digits[i]) == false)
			data_error(data);
		numbers[i] = ft_atoi(digits[i]);
		i++;
	}
	finding_duplicates(data, numbers, stack_size);
	ranking_numbers(numbers, stack->buffer, stack_size);
	stack->i_bottom = stack_size - 1;
	free(numbers);
}

void	data_error(t_push_swap *data)
{
	free_data(data);
	ft_putendl_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_data(t_push_swap *data)
{
	if (data->stack_a.buffer)
		free(data->stack_a.buffer);
	if (data->stack_b.buffer)
		free(data->stack_b.buffer);
	if (data->operations_list)
		ft_lstclear(&data->operations_list, NULL);
}
