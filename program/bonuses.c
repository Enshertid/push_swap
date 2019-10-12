/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:23:57 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_first_ac(t_stacks *point, char *str)
{
	if (!ft_strcmp("-d", str)
		|| !ft_strcmp("-c", str) ||
		!ft_strcmp("-f", str) || !ft_strcmp("-k", str))
	{
		if (!ft_strcmp("-d", str))
			point->debugger = 1;
		else if (!ft_strcmp("-c", str))
			point->color = 1;
		else if (!ft_strcmp("-f", str))
			point->fd = 1;
		else if (!ft_strcmp("-k", str))
			point->commands = 1;
		return (0);
	}
	else
		return (1);
}

void		ft_count_commands(t_stacks *point)
{
	int		op;
	t_stack	*tmp;

	tmp = point->stack_a;
	op = 0;
	while (tmp)
	{
		op += tmp->op;
		tmp = tmp->next;
	}
	if (point->commands)
	{
		if (point->color == 1)
			ft_printf("%fdkRs %kGd\n", point->fd, "operations used ==>", op);
		else
			ft_printf("operations used ==> %fdd\n", point->fd, op);
	}
}

void		ft_debugger(t_stacks *point)
{
	t_stack			*tmp_a;
	t_stack			*tmp_b;

	tmp_a = point->stack_a;
	tmp_b = point->stack_b;
	ft_printf("%kTs", "__________A______________B_______\n");
	while (tmp_a || tmp_b)
	{
		if (tmp_a && tmp_b)
		{
			ft_printf("%kTc%kG*d%kG*d%kT*c\n", '~', 10,
					tmp_a->num, 15, tmp_b->num, 7, '~');
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}
		else
		{
			ft_printf("%kTc%kG*d%kT*c\n", '~', tmp_a ? 10 : 25,
					tmp_a ? tmp_a->num : tmp_b->num, tmp_a ? 22 : 7, '~');
			if (tmp_a)
				tmp_a = tmp_a->next;
			else
				tmp_b = tmp_b->next;
		}
	}
}
