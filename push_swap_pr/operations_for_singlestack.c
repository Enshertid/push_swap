/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_singlestack.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:48:43 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/08 12:42:08 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_swap_stack(t_stack **stack, int type)
{
	t_stack *tmp;

	if (stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
		(*stack)->op++;
	}
	if (type == 1)
		ft_printf("sa\n%fd", 0);
	else
		ft_printf("sb\n%fd", 0);
}

void			ft_push_stack(t_stack **src, t_stack **dst, int type)
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
		(*dst)->next= NULL;
	}
	if (*dst)
		(*dst)->op++;
	if (type == 1)
		ft_printf("pa\n%fd", 0);
	else
		ft_printf("pb\n%fd", 0);
}

void			ft_rotate_stack(t_stack **head, int type, int solo)
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
		(*head)->op++;
	}
	if (type == 1 && solo == 1)
		ft_printf("ra\n%fd", 0);
	else if (type == 0 && solo == 1)
		ft_printf("rb\n%fd", 0);
}

void			ft_reverse_rotate(t_stack **head, int type, int solo)
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
		(*head)->op++;
	}
	if (type == 1 && solo == 1)
		ft_printf("rra\n%fd", 0);
	else if (type == 0 && solo == 1)
		ft_printf("rrb\n%fd", 0);
}