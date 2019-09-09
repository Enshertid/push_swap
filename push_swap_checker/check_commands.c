/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:53:13 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/09 11:53:13 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			ft_command_add(char *ln, t_stacks *point)
{
	if (ft_strcmp(ln, "pa") == 0)
		point->commands->command = push_a;
	else if (ft_strcmp(ln, "pb") == 0)
		point->commands->command = push_b;
	else if (ft_strcmp(ln, "sa") == 0)
		point->commands->command = swap_a;
	else if (ft_strcmp(ln, "sb") == 0)
		point->commands->command = swap_b;
	else if (ft_strcmp(ln, "ss") == 0)
		point->commands->command = swap_both;
	else if (ft_strcmp(ln, "ra") == 0)
		point->commands->command = rotate_a;
	else if (ft_strcmp(ln, "rb") == 0)
		point->commands->command = rotate_b;
	else if (ft_strcmp(ln, "rr") == 0)
		point->commands->command = rotate_both;
	else if (ft_strcmp(ln, "rra") == 0)
		point->commands->command = reverse_a;
	else if (ft_strcmp(ln, "rrb") == 0)
		point->commands->command = reverse_b;
	else if (ft_strcmp(ln, "rrr") == 0)
		point->commands->command = reverse_both;
	else
		return(0);
	return (1);
}

int			ft_check_commands(t_stacks *point)
{
	char		*ln;

	while (ft_get_next_line(1, &ln) > 0)
	{
		if (!point->commands)
			point->commands = ft_list_create(0, 0);
		else
			ft_list_of_command_add(&point->commands, ft_list_create(0, 0));
		if (!ft_command_add(ln, point))
		{
			printf("Error\n");
			return (0);
		}
		free(ln);
	}
	return (1);
}