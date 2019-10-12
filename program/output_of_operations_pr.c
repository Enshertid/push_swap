/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_of_operations_pr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:36:59 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 11:36:59 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_out_rotate(int type, int solo, t_stacks *point)
{
	if (type == 1 && solo == 1 && point->color == 0)
		ft_printf("%fds", point->fd, "ra\n");
	else if (type == 0 && solo == 1 && point->color == 0)
		ft_printf("%fds", point->fd, "rb\n");
	else if (type == 1 && solo == 1 && point->color == 1)
		ft_printf("%fdkGs", point->fd, "ra\n");
	else if (type == 0 && solo == 1 && point->color == 1)
		ft_printf("%fdkGs", point->fd, "rb\n");
	if (point->debugger && solo == 1)
	{
		ft_debugger(point);
		ft_printf("%kTs", "_________________________________\n");
	}
}

void			ft_output_ofpush(int type, t_stacks *point)
{
	if (type == 1 && point->color == 0)
		ft_printf("%fds", point->fd, "pa\n");
	else if (type == 0 && point->color == 0)
		ft_printf("%fds", point->fd, "pb\n");
	else if (type == 1 && point->color == 1)
		ft_printf("%fdkGs", point->fd, "pa\n");
	else if (type == 0 && point->color == 1)
		ft_printf("%fdkGs", point->fd, "pb\n");
	if (point->debugger)
	{
		ft_debugger(point);
		ft_printf("%kTs", "_________________________________\n");
	}
}
