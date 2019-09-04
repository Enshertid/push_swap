//
// Created by Yaxley Manilow on 03/09/2019.
//

#include "push_swap.h"


t_stacks		*ft_struct_create()
{
	t_stacks *point;

	if (!(point = malloc(sizeof(t_stacks))))
		return (NULL);
	return (point);
}

t_stack			*ft_listofstack_create(int a)
{
	t_stack *stack;

	if (!(stack = malloc(sizeof(t_stack))))
		return (NULL);
	stack->num = a;
	stack->next = NULL;
	return (stack);
}

void			ft_list_delete(t_stacks *point)
{
	t_stack *tmp;

	while (point->head)
	{
		tmp = point->head;
		point->head = point->head->next;
		free(tmp);
	}
	free(point->head);
	free(point);
}

