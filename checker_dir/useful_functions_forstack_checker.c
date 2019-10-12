/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions_forstack.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:55:37 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/11 13:32:11 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				ft_check_repeats(t_stacks point)
{
	int		*array;
	int		i;
	int		ln;

	ln = ft_check_lenght_of_stack(point.stack_a);
	array = ft_memalloc(ln * sizeof(int));
	i = 0;
	while (i < ln)
	{
		array[i++] = point.stack_a->num;
		point.stack_a = point.stack_a->next;
	}
	ft_sortof_array(array, ln);
	i = 0;
	while (i < ln - 1)
	{
		if (array[i] == array[i + 1])
		{
			free(array);
			return (0);
		}
		i++;
	}
	free(array);
	return (1);
}

void			ft_stack_list_add(t_stack **head, t_stack *new)
{
	t_stack		*tmp;

	if (head && new)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		new->next = NULL;
		tmp->next = new;
	}
}

void			ft_list_of_command_add(t_command **head, t_command *new)
{
	t_command *tmp;

	if (head && new)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		new->next = NULL;
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
	if (stack)
	{
		while (i < ln)
		{
			printf("%d\n", stack->num);
			if (stack->next)
				stack = stack->next;
			i++;
		}
		printf("end of stack\n");
	}
}
