/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions_forstack.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:55:37 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/09 16:57:37 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_stack_list_add(t_stack **head, t_stack *new)
{
	t_stack *tmp;

	if (head && new)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int				ft_check_lenght_of_stack(t_stack *stack)
{
	int		i;

	i = 0;
	if (stack)
	{
		while (stack->next)
		{
			stack = stack->next;
			i++;
		}
		if (stack)
			i++;
	}
	return (i);
}

void			ft_print_stack(t_stack *stack, int ln)
{
	int i;

	i = 0;
	ft_printf("\nstart of stack\n");
	if (stack)
	{
		while (i < ln)
		{
			ft_printf("%d\n", stack->num);
			if (stack->next)
				stack = stack->next;
			i++;
		}
		ft_printf("end of stack\n");
	}
}
