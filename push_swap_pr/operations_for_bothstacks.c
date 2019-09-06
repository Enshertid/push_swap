/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_for_bothstacks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:55:23 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/06 09:55:57 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next)
		ft_swap_stack(stack_a);
	if (*stack_b && (*stack_b)->next)
		ft_swap_stack(stack_b);
}

void			ft_rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next)
		ft_rotate_stack(stack_a);
	if (*stack_b && (*stack_b)->next)
		ft_rotate_stack(stack_b);
}

void			ft_reverse_all(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next)
		ft_reverse_rotate(stack_a);
	if (*stack_b && (*stack_b)->next)
		ft_reverse_rotate(stack_b);
}