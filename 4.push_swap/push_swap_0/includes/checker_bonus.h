/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:34:15 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/09 20:46:10 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

# define COLOURED_OK "\033[1;32mOK\033[0m\n"
# define COLOURED_KO "\033[1;31mKO\033[0m\n"

typedef struct s_flag
{
	bool	is_colour;
	bool	is_show_stack;
	bool	write_mode;
	bool	found_at_end;
	int		num_start;
	int		num_end;
	int		i_cflag;
	int		i_dash;
	int		index;
}	t_flag;


void	get_operations_list(t_push_swap *data);
bool	is_correctly_sorted(t_push_swap *data);

void	init_and_validate_data_bonus(t_push_swap *data, int ac, char **av, \
		t_flag flag);
bool	validate_numbers_bonus(char *digits);

void	init_flags(int ac, t_flag *flag);
void	check_flags(int ac, char **av, t_flag *flag, t_push_swap *data);
char	**get_digits_n_stack_size(int ac, char **av, int *stack_size, t_flag flag);

void	validate_flags(t_push_swap *data, char **av, t_flag *flag);

#endif
