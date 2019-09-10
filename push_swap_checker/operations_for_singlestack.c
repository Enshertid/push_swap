/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_singlestack.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:51:11 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/09 13:57:09 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_swap_stack(t_stack **stack, t_stacks *point)
{
	t_stack *tmp;

	if (stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
		point->commands = point->commands->next;
	}
}

void			ft_push_stack(t_stack **src, t_stack **dst, t_stacks *point)
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
	else if (*src && (*src)->next)
	{
		tmp = (*src)->next;
		*dst = *src;
		*src = tmp;
		(*src)->next = tmp->next;
		(*dst)->next = NULL;
	}
	point->commands = point->commands->next;
}

void			ft_rotate_stack(t_stack **head, t_stacks *point)
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
		point->commands = point->commands->next;
	}
}

void			ft_reverse_rotate(t_stack **head, t_stacks *point)
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
		point->commands = point->commands->next;
	}
}