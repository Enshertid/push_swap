/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_bothstacks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:55:23 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 11:29:29 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_swap_both(t_stack **stack_a, t_stack **stack_b,
			t_stacks *point)
{
	int		i;

	i = 0;
	if (*stack_a && (*stack_a)->next)
	{
		ft_swap_stack(stack_a, 1, point);
		i = 1;
	}
	if (*stack_b && (*stack_b)->next)
	{
		ft_swap_stack(stack_b, 1, point);
		if (i == 1)
			(*stack_a)->op--;
	}
}

void			ft_rotate_all(t_stack **stack_a,
				t_stack **stack_b, t_stacks *point)
{
	int i;

	i = 0;
	if (*stack_a && (*stack_a)->next)
	{
		ft_rotate_stack(stack_a, 1, 0, point);
		i = 1;
	}
	if (*stack_b && (*stack_b)->next)
	{
		ft_rotate_stack(stack_b, 1, 0, point);
		if (i == 1)
			(*stack_a)->op--;
	}
	if (point->color == 1)
		ft_printf("%fdkGs", point->fd, "rr\n");
	else
		ft_printf("%fds", point->fd, "rr\n");
	if (point->debugger == 1)
	{
		ft_debugger(point);
		ft_printf("%kTs", "_________________________________\n");
	}
}

void			ft_reverse_all(t_stack **stack_a, t_stack **stack_b,
				t_stacks *point)
{
	int		i;

	i = 0;
	if (*stack_a && (*stack_a)->next)
	{
		ft_reverse_rotate(stack_a, 1, 0, point);
		i = 1;
	}
	if (*stack_b && (*stack_b)->next)
	{
		ft_reverse_rotate(stack_b, 1, 0, point);
		if (i == 1)
			(*stack_a)->op--;
	}
	if (!point->color)
		ft_printf("%fds", point->fd, "rrr\n");
	else if (point->color)
		ft_printf("%fdkGs", point->fd, "rrr\n");
	if (point->debugger == 1)
	{
		ft_debugger(point);
		ft_printf("%kTs", "_________________________________\n");
	}
}
