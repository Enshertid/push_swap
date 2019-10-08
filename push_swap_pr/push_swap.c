/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:58:49 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/08 13:10:51 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_error(t_stacks *point)
{
	if (point->stack_a)
		ft_list_delete(point);
	ft_printf("Error\n");
	return (0);
}

void			ft_check_sorted_stack(t_stack **stack, t_stacks *point)
{
	int			ln;
	int			gap;

	ln = ft_check_lenght_of_stack(*stack);
	if ((gap = ft_is_gap(*stack)) > 0)
	{
		if (gap <= ln / 2)
			while ((ft_is_gap(*stack) > 0))
				ft_rotate_stack(&point->stack_a, 1, 1);
		else
			while ((ft_is_gap(*stack) > 0))
				ft_reverse_rotate(&point->stack_a, 1, 1);
	}
	if ((*stack)->num > (*stack)->next->num)
		ft_rotate_stack(&point->stack_a, 1, 1);
}

void			ft_sort_of_stack(t_stacks *point, t_lst *pre_sort)
{
	ft_pre_sort(pre_sort, point);
	while (point->stack_b)
	{
		ft_get_op_b(&point->stack_b);
		ft_get_op_a(point);
		ft_use_op(point);
	}
	ft_check_sorted_stack(&point->stack_a, point);
}

int				main(int ac, char **av)
{
	t_stacks		point;
	t_lst			pre_sort;

	ft_struct_zero(&point, &pre_sort);
	if (!ft_parsing(&point, av, ac, &pre_sort))
		ft_error(&point);
	ft_sort_of_stack(&point, &pre_sort);
	ft_print_stack(point.stack_a, ft_check_lenght_of_stack(point.stack_a));
	ft_list_delete(&point);
	free(pre_sort.array);
	return (0);
}

// стэк меньше трех падает сегой
