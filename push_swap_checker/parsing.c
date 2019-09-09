/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:13:37 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/07 17:52:58 by ymanilow         ###   ########.fr       */
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

void		ft_getting_numbers(t_stacks *point, char *str)
{
	int num;

	while (*str)
	{
		while (!ft_isdigit(*str))
			str++;
		num = ft_atoi(str);
		if ((point)->stack_a)
			ft_stack_list_add(&(point)->stack_a, ft_list_create(num, 1));
		else
			(point)->stack_a = ft_list_create(num, 1);
		while (ft_isdigit(*str))
			str++;
	}
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
	while (i < ln)
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
		ft_getting_numbers(point, str[i++]);
	}
	if(!ft_check_repeats(*point))
	{
		printf("Error\n");
		return(0);
	}
	return (1);
}