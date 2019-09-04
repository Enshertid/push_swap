//
// Created by Yaxley Manilow on 04/09/2019.
//

#include "push_swap.h"

void			ft_stack_list_add(t_stack **stack, t_stack *new)
{
	if (stack && new)
	{
		new->next = *stack;
		*stack = new;
	}
}

int				ft_check_lenght_of_stack(t_stack *stack)
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

void			ft_print_stack(t_stack *stack, int ln)
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
