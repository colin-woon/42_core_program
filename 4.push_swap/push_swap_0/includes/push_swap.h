/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:12:49 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/29 00:37:58 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stdbool.h>
#include <errno.h>
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"
#include "stack.h"

typedef struct s_push_swap
{
  t_stack stack_a;
  t_stack stack_b;
  t_list *operations_list;
  bool write_mode;
} 	t_push_swap;

// Utils Data
void	data_error(t_push_swap *data);
void	free_data(t_push_swap *data);
void	initialize_data(t_push_swap *data, int ac,char **av,bool write_mode);
void	initialize_stack(t_push_swap *data, t_stack *stack, int stack_size);
void	fill_stack(t_push_swap *data, t_stack *stack, \
int stack_size, char **digits);

// Utils Validate
bool	validate_numbers(char *digits);
void	finding_duplicates(t_push_swap *data, int *numbers, int stack_size);
void	ranking_numbers(int *numbers, int *stack_a, int size);

#endif
