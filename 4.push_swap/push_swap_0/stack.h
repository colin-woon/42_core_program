/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:42:29 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/23 17:55:46 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include "libft.h"

typedef struct s_stack
{
	int *stack;
	int top;
	int bottom;
	int size
}			t_stack;

typedef struct s_push_swap
{
  t_stack stack_a;
  t_stack stack_b;
  t_list operations_list;
  bool write_mode;
} t_push_swap


#endif
