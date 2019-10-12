/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:53:13 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 17:39:41 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int			ft_command_add(char *ln, t_command *new)
{
	if (ft_strcmp(ln, "pa") == 0)
		new->command = push_a;
	else if (ft_strcmp(ln, "pb") == 0)
		new->command = push_b;
	else if (ft_strcmp(ln, "sa") == 0)
		new->command = swap_a;
	else if (ft_strcmp(ln, "sb") == 0)
		new->command = swap_b;
	else if (ft_strcmp(ln, "ss") == 0)
		new->command = swap_both;
	else if (ft_strcmp(ln, "ra") == 0)
		new->command = rotate_a;
	else if (ft_strcmp(ln, "rb") == 0)
		new->command = rotate_b;
	else if (ft_strcmp(ln, "rr") == 0)
		new->command = rotate_both;
	else if (ft_strcmp(ln, "rra") == 0)
		new->command = reverse_a;
	else if (ft_strcmp(ln, "rrb") == 0)
		new->command = reverse_b;
	else if (ft_strcmp(ln, "rrr") == 0)
		new->command = reverse_both;
	else
		return (0);
	return (1);
}

int			ft_check_commands(t_stacks *point)
{
	char		*ln;

	while (ft_get_next_line(0, &ln) > 0)
	{
		if (!point->commands)
			point->commands = ft_list_create(0, 0, ln);
		else
			ft_list_of_command_add(&point->commands, ft_list_create(0, 0, ln));
		free(ln);
	}
	point->head = point->commands;
	return (1);
}
