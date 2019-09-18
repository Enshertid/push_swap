/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:53:13 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/10 12:25:51 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		return(0);
	return (1);
}

int			ft_check_commands(t_stacks *point)
{
	char		*ln;

	int fd;
	fd = open ("/Users/ymanilow/curcus42/push_swap/push_swap_checker/file.txt", O_RDWR);
	while (ft_get_next_line(fd, &ln) > 0)
	{
		if (!point->commands)
		{
			point->commands = ft_list_create(0, 0, ln);
		}
		else
			ft_list_of_command_add(&point->commands, ft_list_create(0, 0, ln));
		free(ln);
	}
	if (!point->commands)
		return (0);
	point->head = point->commands;
	return (1);
}