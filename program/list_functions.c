/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:57:59 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_struct_zero(t_stacks *point, t_lst *pre_sort)
{
	point->stack_a = NULL;
	point->stack_b = NULL;
	point->fd = 0;
	point->color = 0;
	point->debugger = 0;
	point->commands = 0;
	pre_sort->array = NULL;
	pre_sort->max_stack = 0;
	pre_sort->min_stack = 0;
	pre_sort->numb_of_first = 0;
	pre_sort->numb_of_second = 0;
}

t_stack			*ft_listofstack_create(int a)
{
	t_stack *stack;

	if (!(stack = malloc(sizeof(t_stack))))
		return (NULL);
	stack->num = a;
	stack->op_b = 0;
	stack->op_a = 0;
	stack->op = 0;
	stack->next = NULL;
	return (stack);
}

void			ft_list_delete(t_stacks *point)
{
	t_stack		*tmp;

	while (point->stack_a)
	{
		tmp = point->stack_a;
		point->stack_a = point->stack_a->next;
		free(tmp);
	}
	while (point->stack_b)
	{
		tmp = point->stack_b;
		point->stack_b = point->stack_b->next;
		free(tmp);
	}
}
