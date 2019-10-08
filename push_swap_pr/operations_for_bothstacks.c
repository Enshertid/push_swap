/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_bothstacks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:55:23 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/08 11:57:36 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	int i;

	i = 0;
	if (*stack_a && (*stack_a)->next)
	{
		ft_swap_stack(stack_a,1);
		i = 1;
	}
	if (*stack_b && (*stack_b)->next)
	{
		ft_swap_stack(stack_b, 1);
		if (i == 1)
			(*stack_a)->op--;
	}
}

void			ft_rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	int i;

	i = 0;
	if (*stack_a && (*stack_a)->next)
	{
		ft_rotate_stack(stack_a, 1, 0);
		i = 1;
	}
	if (*stack_b && (*stack_b)->next)
	{
		ft_rotate_stack(stack_b, 1, 0);
		if (i == 1)
			(*stack_a)->op--;
	}
	ft_printf ("rr%fd\n", 0);
}

void			ft_reverse_all(t_stack **stack_a, t_stack **stack_b)
{
	int i;

	i = 0;
	if (*stack_a && (*stack_a)->next)
	{
		ft_reverse_rotate(stack_a, 1, 0);
		i = 1;
	}
	if (*stack_b && (*stack_b)->next)
	{
		ft_reverse_rotate(stack_b, 1, 0);
		if (i == 1)
			(*stack_a)->op--;
	}
	ft_printf ("rrr%fd\n", 0);
}