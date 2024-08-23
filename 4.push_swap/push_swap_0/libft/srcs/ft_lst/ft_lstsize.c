/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:18:12 by cwoon             #+#    #+#             */
/*   Updated: 2024/08/23 18:27:35 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
NAME
    ft_lstsize -- returns the number of element in the list
SYNOPSIS
    int *ft_lstsize(t_list *lst);
DESCRIPTION
    Count the number of elements of the list
PARAMETERS
    lst: start of the list
RETURN VALUES
    The size of the list
 */
int	ft_lstsize(t_list *lst)
{
	int		num_of_nodes;
	t_list	*node;

	num_of_nodes = 0;
	if (lst == NULL)
		return (0);
	node = lst;
	while (node != NULL)
	{
		num_of_nodes++;
		node = node->next;
	}
	return (num_of_nodes);
}
