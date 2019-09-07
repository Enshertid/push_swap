/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:57:59 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/07 16:13:49 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


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
	stack->next = NULL;
	return (stack);
}

void			ft_list_delete(t_stacks *point)
{
	t_stack *tmp;
	t_stack *lst;

	lst = point->stack_a;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

