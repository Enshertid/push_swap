/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_bothstacks_checker.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:16:33 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 14:53:44 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			ft_swap_both(t_stack **stack_a, t_stack **stack_b,
													t_stacks *point)
{
	if (*stack_a && (*stack_a)->next)
		ft_swap_stack(stack_a, point, 1);
	if (*stack_b && (*stack_b)->next)
		ft_swap_stack(stack_b, point, 1);
	point->op++;
}

void			ft_rotate_all(t_stack **stack_a, t_stack **stack_b,
													t_stacks *point)
{
	if (*stack_a && (*stack_a)->next)
		ft_rotate_stack(stack_a, point, 0);
	if (*stack_b && (*stack_b)->next)
		ft_rotate_stack(stack_b, point, 0);
	point->commands = point->commands->next;
	point->op++;
}

void			ft_reverse_all(t_stack **stack_a, t_stack **stack_b,
													t_stacks *point)
{
	if (*stack_a && (*stack_a)->next)
		ft_reverse_rotate(stack_a, point, 0);
	if (*stack_b && (*stack_b)->next)
		ft_reverse_rotate(stack_b, point, 0);
	point->commands = point->commands;
	point->op++;
}

void			ft_using_commands(t_stacks *point)
{
	while (point->commands)
	{
		if (point->commands->command == push_a)
			ft_push_stack(&point->stack_b, &point->stack_a, point);
		else if (point->commands->command == push_b)
			ft_push_stack(&point->stack_a, &point->stack_b, point);
		else if (point->commands->command == swap_a)
			ft_swap_stack(&point->stack_a, point, 1);
		else if (point->commands->command == swap_b)
			ft_swap_stack(&point->stack_b, point, 1);
		else if (point->commands->command == swap_both)
			ft_swap_both(&point->stack_a, &point->stack_b, point);
		else if (point->commands->command == rotate_a)
			ft_rotate_stack(&point->stack_a, point, 1);
		else if (point->commands->command == rotate_b)
			ft_rotate_stack(&point->stack_b, point, 1);
		else if (point->commands->command == rotate_both)
			ft_rotate_all(&point->stack_a, &point->stack_b, point);
		else if (point->commands->command == reverse_a)
			ft_reverse_rotate(&point->stack_a, point, 1);
		else if (point->commands->command == reverse_b)
			ft_reverse_rotate(&point->stack_b, point, 1);
		else if (point->commands->command == reverse_both)
			ft_reverse_all(&point->stack_a, &point->stack_b, point);
	}
}
