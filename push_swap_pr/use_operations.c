/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:04:43 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/08 13:04:43 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_use_without_synchrone(int op_a, int
op_b, t_stacks *point, int type)
{
	t_stack **stack_a;
	t_stack **stack_b;

	if (type == 1)
	{
		stack_a = &point->stack_a;
		stack_b = &point->stack_b;
	}
	else
	{
		stack_b = &point->stack_a;
		stack_a = &point->stack_b;
	}
	while (op_a != 0)
	{
		op_a--;
		ft_rotate_stack(stack_a, 1, 1);
	}
	while (op_b != 0)
	{
		op_b--;
		ft_reverse_rotate(stack_b, 0, 0);
	}
}

void			ft_use_reverse_rotate(t_stacks *point, int op_a, int op_b)
{
	if (op_a > op_b)
		while (op_a != op_b)
		{
			ft_reverse_rotate(&point->stack_a, 1, 1);
			op_a--;
		}
	else if (op_b > op_a)
		while (op_b != op_a)
		{
			ft_reverse_rotate(&point->stack_b, 0, 1);
			op_b--;
		}
	while (op_a != 0)
	{
		ft_reverse_all(&point->stack_a, &point->stack_b);
		op_a--;
	}
}

void			ft_use_rotate(t_stacks *point, int op_a, int op_b)
{
	if (op_a != op_b)
	{
		if (op_a > op_b)
			while (op_a != op_b)
			{
				ft_rotate_stack(&point->stack_a, 1, 1);
				op_a--;
			}
		else
			while (op_b != op_a)
			{
				ft_rotate_stack(&point->stack_b, 0, 1);
				op_b--;
			}
	}
	while (op_a != 0)
	{
		ft_rotate_all(&point->stack_a, &point->stack_b);
		op_a--;
	}
}

void			ft_use_operation(t_stack *tmp, t_stacks *point)
{
	int				op_a;
	int				op_b;

	op_a = tmp->op_a;
	op_b = tmp->op_b;
	if (ft_synchrone(op_a, op_b))
	{
		if (op_a > 0)
			ft_use_rotate (point, op_a, op_b);
		else if (op_a < 0)
			ft_use_reverse_rotate(point, ft_mod_num(op_a), ft_mod_num(op_b));
	}
	else
	{
		if (op_a >= 0 && op_b <= 0)
			ft_use_without_synchrone(op_a, ft_mod_num(op_b), point, 1);
		else if (op_a <= 0 && op_b >= 0)
			ft_use_without_synchrone(op_b, ft_mod_num(op_a), point, 0);
	}
	ft_push_stack(&point->stack_b, &point->stack_a, 0);
}

void			ft_use_op(t_stacks *point)
{
	int			best;
	t_stack		*tmp_b;
	t_stack		*tmp_best;

	best = 9999;
	tmp_best = point->stack_b;
	tmp_b = point->stack_b;
	while (tmp_b)
	{
		if (ft_synchrone(tmp_b->op_a, tmp_b->op_b) == 1 &&
			best > ft_check_with_synchrone(tmp_b))
		{
			best = ft_check_with_synchrone(tmp_b);
			tmp_best = tmp_b;
		}
		else if (ft_synchrone(tmp_b->op_a, tmp_b->op_b) == 0 &&
				 best > ft_check_without_synchrone(tmp_b))
		{
			best = ft_check_without_synchrone(tmp_b);
			tmp_best = tmp_b;
		}
		tmp_b = tmp_b->next;
	}
	ft_use_operation(tmp_best, point);
}