//
// Created by Yaxley Manilow on 04/09/2019.
//

#include "push_swap.h"

void		ft_swap_onestack(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tmp1;

	tmp = *stack;
	tmp1 = (*stack)->next;
	*stack = tmp1;
	tmp1 = (*stack)->next;
	tmp->next = tmp1;
	(*stack)->next = tmp;
}

void			ft_push_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	t_stack *tmp1;

	if (stack_b && stack_a)
	{
		tmp1 = *stack_b;
		(*stack_b) = *stack_a;
		(*stack_b)->next = tmp1;
		if ((*stack_a)->next)
		{
			tmp = (*stack_a)->next;
			*stack_a = tmp;
		}
		else
			(*stack_a) = NULL;
	}
	else if (stack_a)
	{
		tmp = (*stack_a)->next;
		*stack_b = *stack_a;
		(*stack_a)->next = tmp->next;
		*stack_a = tmp;
		(*stack_b)->next = NULL;
	}
}