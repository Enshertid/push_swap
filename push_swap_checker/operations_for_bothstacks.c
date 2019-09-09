/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_bothstacks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:55:23 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/09 13:57:09 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_swap_both(t_stack **stack_a, t_stack **stack_b, t_stacks *point)
{
	if (*stack_a && (*stack_a)->next)
		ft_swap_stack(stack_a, point);
	if (*stack_b && (*stack_b)->next)
		ft_swap_stack(stack_b, point);
}

void			ft_rotate_all(t_stack **stack_a, t_stack **stack_b, t_stacks *point)
{
	if (*stack_a && (*stack_a)->next)
		ft_rotate_stack(stack_a, point);
	if (*stack_b && (*stack_b)->next)
		ft_rotate_stack(stack_b, point);
}

void			ft_reverse_all(t_stack **stack_a, t_stack **stack_b, t_stacks *point)
{
	if (*stack_a && (*stack_a)->next)
		ft_reverse_rotate(stack_a, point);
	if (*stack_b && (*stack_b)->next)
		ft_reverse_rotate(stack_b, point);
}

void		ft_using_commands(t_stacks *point)
{
	while (point->commands)
	{
		if (point->commands->command == push_a)
			ft_push_stack(&point->stack_a, &point->stack_b, point);
		else if (point->commands->command == push_b)
			ft_push_stack(&point->stack_b, &point->stack_a, point);
		else if (point->commands->command == swap_a)
			ft_swap_stack(&point->stack_a, point);
		else if (point->commands->command == swap_b)
			ft_swap_stack(&point->stack_b, point);
		else if (point->commands->command == swap_both)
			ft_swap_both(&point->stack_a, &point->stack_b, point);
		else if (point->commands->command == rotate_a)
			ft_rotate_stack(&point->stack_a, point);
		else if (point->commands->command == rotate_b)
			ft_rotate_stack(&point->stack_b, point);
		else if (point->commands->command == rotate_both)
			ft_rotate_all(&point->stack_a, &point->stack_b, point);
		else if (point->commands->command == reverse_a)
			ft_reverse_rotate(&point->stack_a, point);
		else if (point->commands->command == reverse_b)
			ft_reverse_rotate(&point->stack_b, point);
		else if (point->commands->command == reverse_both)
			ft_reverse_all(&point->stack_a, &point->stack_b, point);
	}
}