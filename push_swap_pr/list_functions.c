/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:57:59 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/11 15:28:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_struct_zero(t_stacks *point)
{
	point->stack_a = NULL;
	point->stack_b = NULL;
}

t_stack			*ft_listofstack_create(int a)
{
	t_stack *stack;

	if (!(stack = malloc(sizeof(t_stack))))
		return (NULL);
	stack->num = a;
	stack->op_b = 0;
	stack->op_a = 0;
	stack->numb = 0;
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

