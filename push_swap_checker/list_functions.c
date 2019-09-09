/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:57:59 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/09 11:39:41 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


void		ft_struct_zero(t_stacks *point)
{
	point->stack_a = NULL;
	point->stack_b = NULL;
	point->commands = NULL;
}

void			*ft_list_create(int a, int type)
{
	t_stack		*stack;
	t_command	*new;


	if (type == 1)
	{
		if (!(stack = malloc(sizeof(t_stack))))
			return (NULL);
		stack->num = a;
		stack->next = NULL;
		return (stack);
	}
	else
	{
		if (!(new = malloc(sizeof(t_command))))
			return (NULL);
		new->next = NULL;
		return(new);
	}
}

void			ft_list_delete(t_stacks *point)
{
	t_stack		*tmp;
	t_command	*tmp1;

	while (point->stack_a)
	{
		tmp = point->stack_a;
		point->stack_a = point->stack_a->next;
		free(tmp);
	}
	while (point->commands)
	{
		tmp1 = point->commands;
		point->commands = point->commands->next;
		free(tmp1);
	}
}

