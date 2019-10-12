/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:04:27 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 18:13:49 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				ft_check_sorted_list(t_stacks point)
{
	int		*array;
	int		i;
	int		ln;

	if (point.stack_b)
		return (0);
	ln = ft_check_lenght_of_stack(point.stack_a);
	array = ft_memalloc(ln * sizeof(int));
	i = 0;
	while (i < ln)
	{
		array[i++] = point.stack_a->num;
		point.stack_a = point.stack_a->next;
	}
	i = -1;
	while (++i < ln - 1)
	{
		if (array[i] > array[i + 1])
		{
			free(array);
			return (0);
		}
	}
	free(array);
	return (1);
}

int				ft_check_first_ac(t_stacks *point, char *str)
{
	if (!ft_strcmp("-d", str)
		|| !ft_strcmp("-c", str) ||
		!ft_strcmp("-f", str) || !ft_strcmp("-k", str))
	{
		if (!ft_strcmp("-d", str))
			point->debugger = 1;
		else if (!ft_strcmp("-c", str))
			point->color = 1;
		else if (!ft_strcmp("-k", str))
			point->comands = 1;
		return (0);
	}
	else
		return (1);
}

void			ft_usage(void)
{
	ft_printf("%kTs\n%kPs%kRs\n%kTs%kbs\n%kGs\n",
			"CHECKER {USAGE}", "To use checker as usual :\n",
			"./checker [stack] ||"" ./checker \"[part_of_stack]\""
			"\"[part_of_stack]\"...\"[part_of_stack]\"", "Bonuses:\n",
			"./checker \"-c\" \"stack\" => Colored Output",
			"./checker \"-k\" \"stack\" => Output number of commands");
	exit(0);
}

void			ft_error(t_stacks *point)
{
	if (point->color == 1)
		ft_printf("%fdkRs", 2, "Error\n");
	else
		ft_printf("%fds", 2, "Error\n");
	if (point->stack_a)
		ft_list_delete(point);
	exit(0);
}
