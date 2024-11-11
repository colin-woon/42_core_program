/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:15:12 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/11 11:11:23 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Function *f returns (void *) and taking (void *)
 *
 * Function *del returns (void) and taking (void *)
 *
 * Iterates the list ’lst’ and applies the function ’f’
 * on the content of each node. Creates a new list resulting
 * of the successive applications of the function ’f’.
 * The ’del’ function is used to delete the content of
 * a node if needed.
 *
 * (0) lst is an already existing list.
 * (1) Check if lst is empty or NULL.
 * (2) Create and intially assign new list to NULL.
 * (3) If function f is valid, create new node using function f
 *     modifying content.
 * (4) If function f is not valid, create new node and just
 *     assign current content to new node.
 * (4.5) If assigned new node failed, or NULL, delete whole new list.
 * (5) Append the new node to new list.
 * (6) Move lst by making lst as lst.next.
 * (7) Return new list.
 */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		if (f)
			new_node = ft_lstnew(f(lst->content));
		else
			new_node = ft_lstnew(lst->content);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*#include <stdio.h>

void	*touppercase_transform(void *content)
{
	char *str = (char *)content;
	char *new_str = ft_strdup(str);

	for (int i = 0; new_str[i]; i++)
		new_str[i] = ft_toupper(str[i]);
	return ((void *)new_str);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int main()
{
	t_list *head = ft_lstnew(ft_strdup("first"));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("second")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("third")));

	t_list *new_list = ft_lstmap(head, touppercase_transform, NULL);
	
	print_list(new_list);

	ft_lstclear(&head, free);
	ft_lstclear(&new_list, free);

	return (0);
}*/
