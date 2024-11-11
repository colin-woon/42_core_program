/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:50:17 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/11 11:16:21 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* It takes pointer to first node in the list (*lst)
   and return the last node of the list (*lst)
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*#include <stdio.h>

int main()
{
	t_list *head = ft_lstnew(ft_strdup("first"));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("second")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("third")));

	t_list *last = ft_lstlast(head);

	printf("%s\n", (char *)last->content);

	ft_lstclear(&head, free);

	return (0);
}*/
