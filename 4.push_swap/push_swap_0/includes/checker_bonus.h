/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:34:15 by cwoon             #+#    #+#             */
/*   Updated: 2024/09/07 15:57:42 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

void	get_operations_list(t_push_swap *data);
bool	is_correctly_sorted(t_push_swap *data);

void	init_and_validate_data_bonus(t_push_swap *data, int ac, char **av, \
		bool write_mode);
bool	validate_numbers_bonus(char *digits);

#endif
