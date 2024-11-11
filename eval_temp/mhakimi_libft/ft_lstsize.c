/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:10:57 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/11 10:28:58 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* It takes the first node in the list (t_list *lst)
   and returns size of the whole list (int t_list)
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/*#include <stdio.h>
int main()
{
	t_list *head = ft_lstnew("First");
	t_list *second = ft_lstnew("Second");
	t_list *third = ft_lstnew("Third");

	head->next = second;
	second->next = third;

	int size = ft_lstsize(head);
	printf("List size | %d\n", size);
	free(head);
	free(second);
	free(third);

	return (0);
}*/
