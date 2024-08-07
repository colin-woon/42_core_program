#include "ft_list_size.h"
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == NULL)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}

/*
#include <stdio.h>
t_list *create_node(void *str)
{
	t_list *new_node = 0;

	new_node = malloc(sizeof(t_list));
	new_node->data = str;
	new_node->next = NULL;
	return new_node;
}

int main()
{
	t_list *list = create_node("0");
	list->next = create_node("1");
	list->next->next = create_node("2");
	list->next->next->next = create_node("3");

	printf("list size is %d",ft_list_size(list));
}
 */
