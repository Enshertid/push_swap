/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:58:49 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 18:19:16 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_error(t_stacks *point)
{
	if (point->stack_a)
		ft_list_delete(point);
	if (point->color == 0)
		ft_printf("%fdError\n", 2);
	else
		ft_printf("%fdkRs", 2, "Error\n");
	exit(0);
}

void			ft_usage(void)
{
	ft_printf("%kTs\n%kPs%kRs\n%kTs%kbs\n%kGs\n%kWs\n%kOs\n",
	"PUSH_SWAP {USAGE}", "To use push_swap as usual :\n",
	"./push_swap [stack] ||"" ./pus_swap \"[part_of_stack]\""
	"\"[part_of_stack]\"...\"[part_of_stack]\"", "Bonuses:\n",
	"./push_swap \"-d\" \"stack\" => Debugger",
	"./push_swap \"-c\" \"stack\" => Colored Output",
	"./push_swap \"-f\" \"stack\" => Writing to file",
	"./push_swap \"-k\" \"stack\" => Output number of commands");
	exit(0);
}

int				main(int ac, char **av)
{
	t_stacks		point;
	t_lst			pre_sort;

	ft_struct_zero(&point, &pre_sort);
	if (!ft_parsing(&point, av, ac, &pre_sort))
		ft_error(&point);
	ft_sort_of_stack(&point, &pre_sort);
	ft_count_commands(&point);
	ft_list_delete(&point);
	free(pre_sort.array);
	return (0);
}
