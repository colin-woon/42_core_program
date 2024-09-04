/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:42:29 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/04 14:13:30 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct s_push_swap	t_push_swap;
typedef struct s_circular_buffer_stack
{
	int	*buffer;
	int	i_top;
	int	i_bottom;
	int	size;
}	t_stack;

typedef enum e_stack_operations
{
	null_op,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	sa,
	sb,
	ss
}	t_operations;

// Utils Stack
int				get_current_size(t_stack *stack);
bool			is_full(t_stack *stack);
int				get_index_up(t_stack *stack, int index);
int				get_index_down(t_stack *stack, int index);
int				get_stack_value(t_stack *stack, int nth_value);

// Utils Operations
void			save_operation(t_push_swap *data, t_operations op);
t_operations	op_from(t_list *node);
const char		*op_to_string(t_operations op);
void			print_operations(t_list *head);

// Utils Optimization
t_operations	get_double_operation(t_operations now_op, t_operations next_op);
bool			is_useless_operations(t_operations now_op, \
				t_operations next_op);
bool			is_valid_list(t_list *optimized);
void			save_optimized_operation(t_list **optimized, \
				t_operations optimized_op);

// Stack ADT Operations
// Swap
void			swap_a(t_push_swap *data);
void			swap_b(t_push_swap *data);
void			swap_ab(t_push_swap *data);
// Push
void			push_a(t_push_swap *data);
void			push_b(t_push_swap *data);
// Rotate
void			rotate_a(t_push_swap *data);
void			rotate_b(t_push_swap *data);
void			rotate_ab(t_push_swap *data);
// Reverse Rotate
void			r_rotate_a(t_push_swap *data);
void			r_rotate_b(t_push_swap *data);
void			r_rotate_ab(t_push_swap *data);

#endif
