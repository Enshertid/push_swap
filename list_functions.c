//
// Created by Yaxley Manilow on 03/09/2019.
//A

#include "push_swap.h"

void			ft_list_delete(t_stack *head)
{
	t_stack *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}

void			ft_list_add(t_stack **stack, t_stack *new)
{
	if (stack && new)
	{
		new->next = *stack;
		*stack = new;
	}
}

t_stack			*ft_list_create(int a)
{
	t_stack *stack;

	if (!(stack = malloc(sizeof(t_stack))))
		return (NULL);
	stack->num = a;
	stack->next = NULL;
	return (stack);
}

int				ft_check_lenght_of_list(t_stack *stack)
{
	int		i;

	i = 0;
	if (stack)
	{
		while (stack->next)
		{
			stack = stack->next;
			i++;
		}
		if (stack)
			i++;
	}
	return (i);
}

void			ft_print_list(t_stack *stack, int ln)
{
	int i;

	i = 0;
	if (stack)
	{
		while (i < ln)
		{
			printf("%d\n", stack->num);
			if (stack->next)
				stack = stack->next;
			i++;
		}
		printf("end of stack\n");
	}
}