/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_op_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:28:02 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_check_middle(t_stacks *point, int gap, t_stack *tmp_b)
{
	t_stack		*tmp_a;
	int			i;
	int			ln;

	i = 0;
	tmp_a = point->stack_a;
	ln = ft_check_lenght_of_stack(point->stack_a);
	while (i < gap)
	{
		i++;
		tmp_a = tmp_a->next;
	}
	if (tmp_b->num < tmp_a->num)
		i++;
	if (i <= ln / 2)
		tmp_b->op_a = i;
	else
		tmp_b->op_a = i - ln;
}

void			ft_left_side(t_stacks *point, t_stack *tmp_b)
{
	int			i;
	int			ln;
	t_stack		*tmp_a;

	i = 0;
	ln = ft_check_lenght_of_stack(point->stack_a);
	tmp_a = point->stack_a;
	while (tmp_b->num > tmp_a->num)
	{
		i++;
		tmp_a = tmp_a->next;
	}
	if (i <= ln)
		tmp_b->op_a = i;
	else
		tmp_b->op_a = i - ln;
}

void			ft_right_side(t_stacks *point, int gap, t_stack *tmp_b)
{
	int			i;
	int			ln;
	t_stack		*tmp_a;

	i = 0;
	ln = ft_check_lenght_of_stack(point->stack_a);
	tmp_a = point->stack_a;
	while (i <= gap)
	{
		tmp_a = tmp_a->next;
		i++;
	}
	while (tmp_b->num > tmp_a->num)
	{
		i++;
		tmp_a = tmp_a->next;
	}
	if (i <= ln / 2)
		tmp_b->op_a = i;
	else
		tmp_b->op_a = i - ln;
}

void			ft_check_side(t_stacks *point, int gap, t_stack *tmp_b)
{
	int			bottom;
	t_stack		*tmp_a;

	tmp_a = point->stack_a;
	while (tmp_a->next)
		tmp_a = tmp_a->next;
	bottom = tmp_a->num;
	if (tmp_b->num > bottom)
		ft_left_side(point, tmp_b);
	if (tmp_b->num < bottom)
		ft_right_side(point, gap, tmp_b);
}
