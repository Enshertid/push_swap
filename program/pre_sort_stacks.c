/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:27:48 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/11 22:51:30 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_pre_sort_a(t_stack **stack, t_stacks *point)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	if (((*stack)->num < (*stack)->next->num) && (((*stack)->num < tmp->num &&
	(*stack)->next->num > tmp->num) || (*stack)->num > tmp->num))
	{
		ft_reverse_rotate(stack, 1, 1, point);
		if ((*stack)->num > (*stack)->next->num)
			ft_swap_stack(stack, 1, point);
	}
	else if (((*stack)->num > (*stack)->next->num) &&
	(((*stack)->next->num > tmp->num || ((*stack)->num < tmp->num))))
	{
		ft_swap_stack(stack, 1, point);
		if ((*stack)->next->num > tmp->num)
			ft_reverse_rotate(stack, 1, 1, point);
	}
	else if ((*stack)->num > (*stack)->next->num &&
			(*stack)->next->num < tmp->num && tmp->num < (*stack)->num)
		ft_rotate_stack(stack, 1, 1, point);
}

void				ft_pre_sort_b(t_stacks *point, t_lst *pre, int num)
{
	if (point->stack_a->num <= pre->array[num] &&
		(point->stack_a->num != pre->min_stack &&
		point->stack_a->num != pre->max_stack))
		ft_push_stack(&point->stack_a, &point->stack_b, 0, point);
	else
		ft_rotate_stack(&point->stack_a, 1, 1, point);
}

void				ft_pre_sort(t_lst *pre, t_stacks *point)
{
	int ln;

	ln = ft_check_lenght_of_stack(point->stack_a);
	ft_sortof_array(pre->array, ln);
	pre->max_stack = pre->array[ln - 1];
	pre->min_stack = pre->array[0];
	pre->numb_of_first = ln / 3;
	pre->numb_of_second = ln / 2 + ln / 4;
	while (ft_check_lenght_of_stack(point->stack_a) > 3)
	{
		if (ft_check_lenght_of_stack(point->stack_b) < pre->numb_of_first)
			ft_pre_sort_b(point, pre, pre->numb_of_first);
		else if (ft_check_lenght_of_stack(point->stack_b) < pre->numb_of_second)
			ft_pre_sort_b(point, pre, pre->numb_of_second);
		else
			ft_pre_sort_b(point, pre, ln - 1);
	}
	ft_pre_sort_a(&point->stack_a, point);
}
