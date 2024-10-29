/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_splits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleow <bleow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 05:28:06 by bleow             #+#    #+#             */
/*   Updated: 2024/10/15 05:32:56 by bleow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Generic cleanup function to free a 2d array.
*/

#include "libft.h"

void	ft_free_splits(char **splits, size_t i)
{
	while (i > 0)
	{
		free(splits[--i]);
	}
	free(splits);
}
