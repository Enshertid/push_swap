/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:58:49 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/08 11:53:13 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_mod_num(int num)
{
	return (num < 0 ? (-num) : num);
}



int				ft_synchrone(int num1, int num2)
{
	if ((num1 < 0 && num2 < 0) || (num1 > 0 && num2 > 0) ||
			(num1 == 0 && num2 == 0))
		return (1);
	return (0);
}

void				ft_use_without_synchrone(int op_a, int op_b, t_stacks *point, int type)
{
	t_stack **stack_a;
	t_stack **stack_b;

	if (type == 1)
	{
		stack_a = &point->stack_a;
		stack_b = &point->stack_b;
	}
	else
	{
		stack_b = &point->stack_a;
		stack_a = &point->stack_b;
	}
	while (op_a != 0)
	{
		op_a--;
		ft_rotate_stack(stack_a, 1, 1);
	}
	while (op_b != 0)
	{
		op_b--;
		ft_reverse_rotate(stack_b, 0, 0);
	}
}

void			ft_use_reverse_rotate(t_stacks *point, int op_a, int op_b)
{
	if (op_a > op_b)
		while (op_a != op_b)
		{
			ft_reverse_rotate(&point->stack_a, 1, 1);
			op_a--;
		}
	else if (op_b > op_a)
		while (op_b != op_a)
		{
			ft_reverse_rotate(&point->stack_b, 0, 1);
			op_b--;
		}
	while (op_a != 0)
	{
		ft_reverse_all(&point->stack_a, &point->stack_b);
		op_a--;
	}
}

void			ft_use_rotate(t_stacks *point, int op_a, int op_b)
{
	if (op_a != op_b)
	{
		if (op_a > op_b)
			while (op_a != op_b)
			{
				ft_rotate_stack(&point->stack_a, 1, 1);
				op_a--;
			}
		else
			while (op_b != op_a)
			{
				ft_rotate_stack(&point->stack_b, 0, 1);
				op_b--;
			}
	}
	while (op_a != 0)
	{
		ft_rotate_all(&point->stack_a, &point->stack_b);
		op_a--;
	}
}


void			ft_use_operation(t_stack *tmp, t_stacks *point)
{
	int				op_a;
	int				op_b;

	op_a = tmp->op_a;
	op_b = tmp->op_b;
	if (ft_synchrone(op_a, op_b))
	{
		if (op_a > 0)
			ft_use_rotate (point, op_a, op_b);
		else if (op_a < 0)
			ft_use_reverse_rotate(point, ft_mod_num(op_a), ft_mod_num(op_b));
	}
	else
	{
		if (op_a >= 0 && op_b <= 0)
			ft_use_without_synchrone(op_a, ft_mod_num(op_b), point, 1);
		else if (op_a <= 0 && op_b >= 0)
			ft_use_without_synchrone(op_b, ft_mod_num(op_a), point, 0);
	}
	ft_push_stack(&point->stack_b, &point->stack_a, 0);
}

int				ft_check_big(int num1, int num2)
{
	return (num1 >= num2 ? num1 : num2);
}

int				ft_check_without_synchrone(t_stack *tmp)
{
	return (ft_mod_num(tmp->op_a) + ft_mod_num(tmp->op_b));
}

int				ft_check_with_synchrone(t_stack *tmp)
{
	if (tmp->op_a > 0)
		return (ft_check_big(tmp->op_a, tmp->op_b));
	else if (tmp->op_a < 0)
		return (ft_check_big(ft_mod_num(tmp->op_a), ft_mod_num(tmp->op_b)));
	else
		return (0);
}

void			ft_use_op(t_stacks *point)
{
	int			best;
	t_stack		*tmp_b;
	t_stack		*tmp_best;

	best = 9999;
	tmp_best = point->stack_b;
	tmp_b = point->stack_b;
	while (tmp_b)
	{
		if (ft_synchrone(tmp_b->op_a, tmp_b->op_b) == 1 &&
			best > ft_check_with_synchrone(tmp_b))
		{
				best = ft_check_with_synchrone(tmp_b);
				tmp_best = tmp_b;
		}
		else if (ft_synchrone(tmp_b->op_a, tmp_b->op_b) == 0 &&
				best > ft_check_without_synchrone(tmp_b))
		{
				best = ft_check_without_synchrone(tmp_b);
				tmp_best = tmp_b;
		}
		tmp_b = tmp_b->next;
	}
	ft_use_operation(tmp_best, point);
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

int				ft_error(t_stacks *point)
{
	if (point->stack_a)
		ft_list_delete(point);
	ft_printf("Error\n");
	return (0);
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
