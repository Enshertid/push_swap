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

void			ft_push_stack(t_stack **src, t_stack **dst)
{
	t_stack *tmp;
	t_stack *tmp1;

	if (*dst && *src)
	{
		tmp1 = *dst;
		*dst = *src;
		if ((*src)->next)
		{
			tmp = (*src)->next;
			*src = tmp;
		}
		else
			(*src) = NULL;
		(*dst)->next = tmp1;
	}
	else if (*src)
	{
		tmp = (*src)->next;
		*dst = *src;
		*src = tmp;
		(*src)->next = tmp->next;
		(*dst)->next = NULL;
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
		tmp->next = *head;
		tmp1->next = NULL;
		*head = tmp;
	}
}