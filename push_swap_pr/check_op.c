/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:48:35 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/08 12:59:13 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int				ft_is_gap(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (tmp->next && tmp->num > tmp->next->num)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void			ft_without_gap(t_stacks *point, t_stack *tmp_b)
{
	t_stack		*tmp_a;
	int			i;
	int			ln;

	i = 0;
	ln = ft_check_lenght_of_stack(point->stack_a);
	tmp_a = point->stack_a;
	while (tmp_a->next && tmp_b->num > tmp_a->num)
	{
		i++;
		tmp_a = tmp_a->next;
	}
	if (i <= ln / 2)
		tmp_b->op_a = i;
	else
		tmp_b->op_a = i - ln;
}

void			ft_with_gap(t_stacks *point, int gap, t_stack *tmp_b)
{
	int			i;
	t_stack		*tmp_a;

	tmp_a = point->stack_a;
	i = 0;
	while (i != gap)
	{
		tmp_a = tmp_a->next;
		i++;
	}
	if (tmp_b->num > tmp_a->num && tmp_b->num < tmp_a->next->num)
		ft_check_middle(point, gap, tmp_b);
	else
		ft_check_side(point, gap, tmp_b);
}

void			ft_get_op_a(t_stacks *point)
{
	t_stack		*tmp_b;
	int			gap;

	tmp_b = point->stack_b;
	while (tmp_b)
	{
		if ((gap = ft_is_gap(point->stack_a)) == 0)
			ft_without_gap(point, tmp_b);
		else
			ft_with_gap(point, gap, tmp_b);
		if (tmp_b->next)
			tmp_b = tmp_b->next;
		else
			break;
	}
}

void			ft_get_op_b(t_stack **stack)
{
	t_stack		*tmp;
	int			ln;
	int			i;

	i = 0;
	ln = ft_check_lenght_of_stack(*stack);
	tmp = *stack;
	while (tmp)
	{
		if (i <= ln / 2)
			tmp->op_b = i;
		else
			tmp->op_b = i - ln;
		i++;
		if (tmp->next)
			tmp = tmp->next;
		else
			break;
	}
}