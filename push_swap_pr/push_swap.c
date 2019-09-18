/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:58:49 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/11 15:28:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_sort_small_stack(t_stack **stack_a)
{
	t_stack *tmp;

	tmp = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	if (((*stack_a)->num > (*stack_a)->next->num &&
				(*stack_a)->next->num < tmp->num) ||
				((*stack_a)->num > (*stack_a)->next->num &&
				(*stack_a)->next->num > tmp->num) ||
			((*stack_a)->num < tmp->num && (*stack_a)->num <
			(*stack_a)->next->num && (*stack_a)->next->num > tmp->num))
		ft_swap_stack(stack_a);
}

void			ft_get_numb(t_stacks *point)
{
	int			i;
	t_stack		*tmp_a;
	t_stack		*tmp_b;

	tmp_a = point->stack_a;
	tmp_b = point->stack_b;
	i = 0;
	while (tmp_a->next)
	{
		tmp_a->numb = i++;
		tmp_a = tmp_a->next;
	}
	tmp_a->numb = i;
	i = 0;
	while (tmp_b->next)
	{
		tmp_b->numb = i++;
		tmp_b = tmp_b->next;
	}
	tmp_b->numb = i;
}

void			ft_priority_on_stacks(t_stack **stack_b, t_stack **stack_a)
{
	t_stack *tmp_b;
	t_stack *tmp_a;
	int ln_a;
	int ln_b;

	ln_a = ft_check_lenght_of_stack(*stack_a);
	ln_b = ft_check_lenght_of_stack(*stack_b);
	tmp_b = *stack_b;
	tmp_b->op_b = tmp_b->numb;
	while (tmp_b->numb  < ln_b / 2)
	{
		tmp_b = tmp_b->next;
		tmp_b->op_b = tmp_b->numb;
	}
	while (tmp_b->next)
	{
		tmp_b = tmp_b->next;
		tmp_b->op_b = ln_b - tmp_b->numb;
	}
	tmp_b = *stack_b;
	tmp_a = *stack_a;
	while (tmp_b)
	{
		while (tmp_a->next && tmp_b->num > tmp_a->num)
			tmp_a = tmp_a->next;
		if (tmp_a->numb == 0)
		{
			while (tmp_a->next && tmp_b->numb < tmp_a->numb)
				tmp_a = tmp_a->next;
			if (tmp_b->num > tmp_a->num)
				tmp_b->op_a = ln_a - tmp_a->numb;
		}
		else if (tmp_b->num < tmp_a->num)
		{
			if (tmp_a->numb < ln_a / 2)
				tmp_b->op_a = tmp_a->numb;
		}
		if (tmp_b->next)
			tmp_b = tmp_b->next;
		else
			break;
		tmp_a = *stack_a;
	}
}

void			ft_operation_on_stacks(t_stacks *point)
{
	int			best;
	int			op_b;
	int			op_a;
	t_stack		*tmp_best;
	t_stack		*tmp_b;

	tmp_best = point->stack_b;
	best = point->stack_b->op_a + point->stack_b->op_b;
	tmp_b = point->stack_b;
	while (tmp_b)
	{
		if (best > tmp_b->op_b + tmp_b->op_a)
		{
			best = tmp_b->op_a + tmp_b->op_b;
			tmp_best = tmp_b;
		}
		if (tmp_b->next)
			tmp_b = tmp_b->next;
		else
			break;
	}
	op_b = tmp_best->op_b;
	op_a = tmp_best->op_a;
	while (op_b > 0)
	{
		ft_rotate_stack(&point->stack_b);
		op_b--;
	}
	while(op_a > 0)
	{
		ft_rotate_stack(&point->stack_a);
		op_a--;
	}
	ft_push_stack(&point->stack_b, &point->stack_a);
}

int				main(int ac, char **av)
{
	t_stacks	point;

	ft_struct_zero(&point);
	if (!ft_parsing(&point, av, ac))
	{
		printf("Error\n");
		return (0);
	}
	ft_print_stack(point.stack_a, ft_check_lenght_of_stack(point.stack_a));
	while (ft_check_lenght_of_stack(point.stack_a) != 3)
		ft_push_stack(&point.stack_a, &point.stack_b);
	ft_print_stack(point.stack_a, ft_check_lenght_of_stack(point.stack_a));
	ft_print_stack(point.stack_b, ft_check_lenght_of_stack(point.stack_b));
	ft_sort_small_stack(&point.stack_a);
	while (point.stack_b)
	{
		ft_get_numb(&point);
		ft_priority_on_stacks(&point.stack_b, &point.stack_a);
		ft_operation_on_stacks(&point);
		ft_print_stack(point.stack_a, ft_check_lenght_of_stack(point.stack_a));
		ft_print_stack(point.stack_b, ft_check_lenght_of_stack(point.stack_b));
	}
	ft_print_stack(point.stack_a, ft_check_lenght_of_stack(point.stack_a));
	ft_list_delete(&point);
	printf("Hello, World!\n");
	return 0;
}