/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:34:15 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/10 18:51:18 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

# define COLOURED_OK "\033[1;32mOK\033[0m\n"
# define COLOURED_KO "\033[1;31mKO\033[0m\n"

typedef struct s_flag
{
	bool	is_display_stack;
	bool	is_colour;
	bool	write_mode;
	bool	found_at_end;
	bool	found_v;
	bool	found_c;
	int		num_start;
	int		num_end;
	int		i_flag;
	int		i_dash;
	int		index;
}	t_flag;

// Utils Checker Bonus
void	get_operations_list(t_push_swap *data);
bool	is_correctly_sorted(t_push_swap *data, t_flag *flag);

// Utils Data Bonus
void	init_and_validate_data_bonus(t_push_swap *data, int ac, char **av, \
		t_flag flag);

// Utils Validate Bonus
bool	validate_numbers_bonus(char *digits);

// Utils Flag Bonus
void	init_flag(int ac, t_flag *flag);
void	check_flag(int ac, char **av, t_flag *flag, t_push_swap *data);
char	**get_digits_n_stack_size(int ac, char **av, int *stack_size, \
		t_flag flag);
void	print_stack(t_stack *stack, char a_or_b);

// Utils Validate Flags Bonus
void	validate_flag(t_push_swap *data, char **av, t_flag *flag);

#endif
