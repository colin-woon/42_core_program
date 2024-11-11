/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:57:46 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/11 09:59:15 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *
 */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/*int main(void) {
    // Create a new node with content "42"
    t_list *node1 = ft_lstnew("42");

    // Create another new node with content "24"
    t_list *node2 = ft_lstnew("24");

    // Add node2 to the back of the list starting with node1
    ft_lstadd_back(&node1, node2);

    // Print the list content to verify that node2 is added to the back
    t_list *current = node1;
    while (current != NULL) {
        printf("Node content: %s\n", (char *)current->content);
        current = current->next;
    }

    // Free the allocated memory for the nodes to avoid memory leaks
    free(node1);
    free(node2);

    return 0;
}*/
