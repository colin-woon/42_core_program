/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:12:54 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/23 20:30:17 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void);
bool	is_valid_number(const char *str);
bool	has_duplicates(int *numbers, int size);
void	process_argument(char *arg, int *numbers, int *size);
int		*convert_and_validate(int argc, char **argv, int *size);
int		*validate_input(int argc, char **argv);

// Function to print "Error\n" and exit the program
void error_exit(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

// Function to check if a string represents a valid integer
bool is_valid_number(const char *str)
{
	long long num;
	int sign;

	sign = 1;
	if (*str == '\0')
		return false;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (*str == '\0')
			return false;
	}
	num = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return false;
		num = num * 10 + (*str - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && -num < INT_MIN))
			return false;
		str++;
	}
	return true;
}

// Function to check for duplicates in an array of integers
bool has_duplicates(int *numbers, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return true;
			j++;
		}
		i++;
	}
	return false;
}

// Function to split arguments and validate them
void process_argument(char *arg, int *numbers, int *size)
{
	char **arg_parts;
	int j;

	arg_parts = ft_split(arg, ' ');
	if (!arg_parts)
		error_exit();
	j = 0;
	while (arg_parts[j])
	{
		if (!is_valid_number(arg_parts[j]))
		{
			free(arg_parts);
			free(numbers);
			error_exit();
		}
		numbers[*size] = ft_atoi(arg_parts[j]);
		(*size)++;
		j++;
	}
	free(arg_parts);
}

// Function to convert the arguments to an array of integers and validate them
int *convert_and_validate(int argc, char **argv, int *size)
{
	int *numbers;
	int i;

	numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		error_exit();
	*size = 0;
	i = 1;
	while (i < argc)
	{
		process_argument(argv[i], numbers, size);
		i++;
	}
	if (has_duplicates(numbers, *size))
	{
		free(numbers);
		error_exit();
	}
	return numbers;
}

// Main validation function
int *validate_input(int argc, char **argv)
{
	int size;
	int *numbers;

	numbers = convert_and_validate(argc, argv, &size);
	return (numbers);
}
