/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_pr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:04:12 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 18:20:06 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_check_sorted_stack(t_stack **stack, t_stacks *point)
{
	int			ln;
	int			gap;

	ln = ft_check_lenght_of_stack(*stack);
	if ((gap = ft_is_gap(*stack)) > 0)
	{
		if (gap <= ln / 2)
			ft_rotate_stack(&point->stack_a, 1, 1,
							point);
		else
			while ((ft_is_gap(*stack) > 0))
				ft_reverse_rotate(&point->stack_a, 1, 1,
						point);
	}
	if ((*stack)->next && (*stack)->num > (*stack)->next->num)
		ft_rotate_stack(&point->stack_a, 1, 1, point);
}

int				ft_check_stack_input(t_stacks *point)
{
	t_stack *tmp;

	tmp = point->stack_a;
	while (tmp)
	{
		if (tmp->next && tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void			ft_sort_of_stack(t_stacks *point, t_lst *pre_sort)
{
	if (ft_check_lenght_of_stack(point->stack_a) >= 3 &&
			!ft_check_stack_input(point))
	{
		ft_pre_sort(pre_sort, point);
		while (point->stack_b)
		{
			ft_get_op_b(&point->stack_b);
			ft_get_op_a(point);
			ft_use_op(point);
		}
	}
	ft_check_sorted_stack(&point->stack_a, point);
}
