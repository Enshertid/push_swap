/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:13:37 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 11:19:30 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_av(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else if (ft_isspace(*str))
			str++;
		else if (*str == '-' && ft_isdigit(*(str + 1)))
			str++;
		else
			return (0);
	}
	return (1);
}

int			ft_getting_numbers(t_stacks *point, char *str)
{
	long int		num;
	int				num1;

	while (*str)
	{
		while (*str && !ft_isdigit(*str) && *str != '-' && *str != '+')
			str++;
		num = ft_atoi(str);
		num1 = num;
		if (num != (long int)num1)
			return (0);
		if ((point)->stack_a)
			ft_stack_list_add(&(point)->stack_a, ft_listofstack_create(num));
		else
			(point)->stack_a = ft_listofstack_create(num);
		if (*str == '-')
			str++;
		while (ft_isdigit(*str))
			str++;
		while (ft_isspace(*str))
			str++;
		if (*str == '-' && *(str - 1) != ' ')
			return (0);
	}
	return (1);
}

int			ft_isonly_spaces(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

int			ft_check_valid(t_stacks *point, char **str, int ac)
{
	int				i;

	i = 1;
	while (!ft_check_first_ac(point, str[i]))
		i++;
	if (point->fd == 1)
	{
		point->fd = open(str[i], O_RDWR, O_APPEND, O_TRUNC);
		i++;
	}
	else if (!point->fd)
		point->fd = 1;
	while (i < ac)
	{
		while (i < ac && ft_isonly_spaces(str[i]))
			i++;
		if (i < ac && !ft_check_av(str[i]))
			return (0);
		if (i < ac && !ft_getting_numbers(point, str[i++]))
			return (0);
	}
	return (1);
}

int			ft_parsing(t_stacks *point, char **str, int ac, t_lst *pre_sort)
{
	int				ln;
	t_stack			*tmp;

	if (ac < 2)
		ft_usage();
	if (!ft_check_valid(point, str, ac))
		return (0);
	if (point->stack_a == NULL)
		exit(0);
	if (!ft_check_repeats(*point))
		return (0);
	ln = ft_check_lenght_of_stack(point->stack_a);
	pre_sort->array = malloc(sizeof(int) * ln);
	tmp = point->stack_a;
	while (tmp)
	{
		pre_sort->array[--ln] = tmp->num;
		tmp = tmp->next;
	}
	return (1);
}
