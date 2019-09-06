/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:55:24 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/06 14:04:41 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			ft_check_av(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else if (ft_isspace(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

void		ft_filling_stack(t_stacks **point, char *str)
{
	int num;

	while (*str)
	{
		while (!ft_isdigit(*str))
			str++;
		num = ft_atoi(str);
		if ((*point)->stack_a)
			ft_stack_list_add(&(*point)->stack_a, ft_listofstack_create(num));
		else
			(*point)->stack_a = ft_listofstack_create(num);
		while (ft_isdigit(*str))
			str++;
	}
	(*point)->head = (*point)->stack_a;
}

int			main(int ac, char **av)
{
	size_t			i;
	t_stacks	*point;

	point = ft_struct_create();
	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		if (!ft_check_av(av[i]))
		{
			printf("Error\n");
			return (0);
		}
		ft_filling_stack(&point, av[i]);
	}
	ft_print_stack(point->stack_a, ft_check_lenght_of_stack(point->stack_a));
	ft_list_delete(point);
	return (0);
}

