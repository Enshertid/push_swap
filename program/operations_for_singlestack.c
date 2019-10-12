/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_singlestack.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:48:43 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_swap_stack(t_stack **stack,
		int type, t_stacks *point)
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
	if (type == 1 && point->color == 0)
		ft_printf("%fds", point->fd, "sa\n");
	else if (type == 0 && point->color == 0)
		ft_printf("%fds", point->color, "sb\n");
	else if (type == 1 && point->color == 1)
		ft_printf("%fdkGs", point->fd, "sa\n");
	else if (type == 0 && point->color == 1)
		ft_printf("%fdkG", point->fd, "sb\n");
	if (point->debugger)
	{
		ft_debugger(point);
		ft_printf("%kTs", "_________________________________\n");
	}
}

void			ft_push_stack(t_stack **src, t_stack **dst,
					int type, t_stacks *point)
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
	if (*dst)
		(*dst)->op++;
	ft_output_ofpush(type, point);
}

void			ft_rotate_stack(t_stack **head, int type,
				int solo, t_stacks *point)
{
	t_stack		*tmp;

	if (*head && (*head)->next)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *head;
		tmp = *head;
		*head = (*head)->next;
		tmp->next = NULL;
		(*head)->op++;
	}
	ft_out_rotate(type, solo, point);
}

void			ft_reverse_rotate(t_stack **head, int type,
					int solo, t_stacks *point)
{
	t_stack *tmp;

	if (*head && (*head)->next)
	{
		tmp = *head;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = *head;
		*head = tmp->next;
		tmp->next = NULL;
		(*head)->op++;
	}
	if (type == 1 && solo == 1 && point->color == 0)
		ft_printf("%fds", point->fd, "rra\n");
	else if (type == 0 && solo == 1 && point->color == 0)
		ft_printf("%fds", point->fd, "rrb\n");
	else if (type == 1 && solo == 1 && point->color == 1)
		ft_printf("%fdkGs", point->fd, "rra\n");
	else if (type == 0 && solo == 1 && point->color == 1)
		ft_printf("%fdkGs", point->fd, "rrb\n");
	if (point->debugger && solo == 1)
	{
		ft_debugger(point);
		ft_printf("%kTs", "_________________________________\n");
	}
}
