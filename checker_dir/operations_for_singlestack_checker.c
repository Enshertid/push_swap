/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_singlestack.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:51:11 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:38:50 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			ft_swap_stack(t_stack **stack, t_stacks *point, int solo)
{
	t_stack *tmp;

	if (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
	if (solo == 1)
	{
		point->op++;
		point->commands = point->commands->next;
	}
}

void			ft_push_stack(t_stack **src, t_stack **dst, t_stacks *point)
{
	t_stack *tmp;

	if (*dst && *src)
	{
		tmp = *src;
		if ((*src)->next)
			*src = (*src)->next;
		else
			(*src) = NULL;
		tmp->next = *dst;
		*dst = tmp;
	}
	else if (*src)
	{
		*dst = *src;
		*src = (*src)->next;
		(*dst)->next = NULL;
	}
	point->op++;
	point->commands = point->commands->next;
}

void			ft_rotate_stack(t_stack **head, t_stacks *point, int solo)
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
	if (solo == 1)
	{
		point->op++;
		point->commands = point->commands->next;
	}
}

void			ft_reverse_rotate(t_stack **head, t_stacks *point, int solo)
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
	if (solo == 1)
	{
		point->op++;
		point->commands = point->commands->next;
	}
}
