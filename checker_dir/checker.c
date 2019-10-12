/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:55:24 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 18:14:29 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				main(int ac, char **av)
{
	t_stacks	point;

	ft_struct_zero(&point);
	if (!ft_parsing(&point, av, ac))
		ft_error(&point);
	if (!ft_check_commands(&point))
		ft_error(&point);
	if (!ft_check_sorted_list(point) && !point.commands)
		ft_error(&point);
	ft_using_commands(&point);
	if (!ft_check_sorted_list(point))
		point.color ? ft_printf("%kGs", "KO\n") :
								ft_printf("KO\n");
	else
		point.color ? ft_printf("%kGs", "OK\n") :
								ft_printf("OK\n");
	if (point.comands == 1)
		point.color == 1 ? ft_printf("%kGs%kRd",
					"operations used ==> ", point.op) :
					ft_printf("operations used ==> %d", point.op);
	ft_list_delete(&point);
	return (0);
}
