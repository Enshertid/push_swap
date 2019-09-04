//
// Created by Yaxley Manilow on 04/09/2019.
//

#include "push_swap.h"

void		ft_swap_stack(t_stack **stack)
{
	t_stack *tmp;

	if (stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
}
void		ft_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next)
		ft_swap_stack(stack_a);
	if (*stack_b && (*stack_b)->next)
		ft_swap_stack(stack_b);
}

void			ft_push_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	t_stack *tmp1;

	if (*stack_b && *stack_a)
	{
		tmp1 = *stack_b;
		*stack_b = *stack_a;
		if ((*stack_a)->next)
		{
			tmp = (*stack_a)->next;
			*stack_a = tmp;
		}
		else
			(*stack_a) = NULL;
		(*stack_b)->next = tmp1;
	}
	else if (*stack_a)
	{
		tmp = (*stack_a)->next;
		*stack_b = *stack_a;
		*stack_a = tmp;
		(*stack_a)->next = tmp->next;
		(*stack_b)->next = NULL;
	}
}

void			ft_rotate_stack(t_stack **head)
{
	t_stack		*tmp;
	t_stack		*tmp1;

	if (*head && (*head)->next)
	{
		tmp = *head;
		tmp1 = (*head)->next;
		while (tmp->next)
			tmp = tmp->next;
		(*head)->next = NULL;
		tmp->next = *head;
		*head = tmp1;
	}
}

void			ft_rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next)
		ft_rotate_stack(stack_a);
	if (*stack_b && (*stack_b)->next)
		ft_rotate_stack(stack_b);
}

void			ft_reverse_rotate(t_stack **head)
{
	t_stack *tmp;
	t_stack *tmp1;

	if (*head && (*head)->next)
	{
		tmp = *head;
		tmp1 = *head;
		while (tmp->next)
			tmp = tmp->next;
		while (tmp1->next != tmp)
			tmp1 = tmp1->next;
		tmp1->next = NULL;
		tmp->next = *head;
		*head = tmp;
	}
}

void			ft_reverse_all(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next)
		ft_reverse_rotate(stack_a);
	if (*stack_b && (*stack_b)->next)
		ft_reverse_rotate(stack_b);
}