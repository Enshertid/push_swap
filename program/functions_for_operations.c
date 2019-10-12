/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:10:55 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:12 by ymanilow         ###   ########.fr       */
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
