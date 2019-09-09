/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:13:37 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/09 16:26:50 by ymanilow         ###   ########.fr       */
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
		else if (*str == '-' && ft_isdigit(*(str + 1)))
			str++;
		else
			return (0);
	}
	return (1);
}

long int	ft_atoi1(const char *str)
{
	long long int	res;
	short int		sign;

	while (ft_isspace(*str))
		++str;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	res = 0;
	while (ft_isdigit(*str))
		res = res * 10 + *str++ - '0';
	return (res * sign);
}

int			ft_getting_numbers(t_stacks *point, char *str)
{
	long long int num;
	int num1;

	while (*str)
	{
		while (!ft_isdigit(*str) && *str != '-')
			str++;
		num = ft_atoi1(str);
		num1 = num;
		if (num != (long long int)num1)
		{
			printf("Error\n");
			return (0);
		}
		if ((point)->stack_a)
			ft_stack_list_add(&(point)->stack_a, ft_list_create(num, 1, NULL));
		else
			(point)->stack_a = ft_list_create(num, 1, NULL);
		while (ft_isdigit(*str) || *str == '-')
			str++;
	}
	return (1);
}

void		ft_sortof_array(int *array, int ln)
{
	int i;
	int j;
	int min;

	i = 0;
	while (i < ln)
	{
		j = i + 1;
		min = array[i];
		while (j < ln)
		{
			if (array[j] < min)
			{
				min = array[j];
				array[j] = array[i];
				array[i] = min;
			}
			j++;
		}
		i++;
	}
}

int		ft_check_repeats(t_stacks point)
{
	int		*array;
	int		i;
	int		ln;

	ln = ft_check_lenght_of_stack(point.stack_a);
	array = ft_memalloc(ln * sizeof(int));
	i = 0;
	while (i < ln)
	{
		array[i++] = point.stack_a->num;
		point.stack_a = point.stack_a->next;
	}
	ft_sortof_array(array, ln);
	i = 0;
	while (i < ln - 1)
	{
		if (array[i] == array[i + 1])
		{
			free(array);
			return (0);
		}
		i++;
	}
	free(array);
	return (1);
}

int			ft_parsing(t_stacks *point, char **str, int ac)
{
	int i;

	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		if (!ft_check_av(str[i]))
		{
			printf("Error\n");
			return (0);
		}
		if (!ft_getting_numbers(point, str[i++]))
			return (0);
	}
	if (!ft_check_repeats(*point))
	{
		printf("Error\n");
		return(0);
	}
	return (1);
}