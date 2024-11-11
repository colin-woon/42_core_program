/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:46:53 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/11 10:07:04 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int main(void) {
    // Create a new node with content "42"
    t_list *node1 = ft_lstnew("42");

    // Create another new node with content "24"
    t_list *node2 = ft_lstnew("24");

    // Add node2 to the front of the list, so it becomes the new head
    ft_lstadd_front(&node1, node2);

    // Print the list content to verify that node2 is now at the front
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
