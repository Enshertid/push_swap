/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:55:24 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/09 11:49:29 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"




int			main(int ac, char **av)
{
	t_stacks	point;

	ft_struct_zero(&point);
	if (!ft_parsing(&point, av, ac))
		return (0);
	ft_print_stack(point.stack_a, ft_check_lenght_of_stack(point.stack_a));
	if (!ft_check_commands(&point))
		return (0);
	ft_list_delete(&point);
	printf("all's fine!!\n");
	return (0);
}

