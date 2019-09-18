/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:55:24 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/10 13:32:06 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


//int				ft_check_lenght_of_command(t_command *head)
//{
//	int		i;
//
//	i = 0;
//	if (head)
//	{
//		while (head->next)
//		{
//			head = head->next;
//			i++;
//		}
//		if (head)
//			i++;
//	}
//	return (i);
//}
//
//void			ft_print_command(t_command *head, int ln)
//{
//	int i;
//
//	i = 0;
//	if (head)
//	{
//		while (i < ln)
//		{
//			if (head->command == push_a)
//				printf("push_a\n");
//			else if (head->command == push_b)
//				printf("push_b\n");
//			else if (head->command == swap_a)
//				printf("swap_a\n");
//			else if (head->command == swap_b)
//				printf("swap_b\n");
//			else if (head->command == swap_both)
//				printf("swap_both\n");
//			else if (head->command == rotate_a)
//				printf("rotate_a\n");
//			else if (head->command == rotate_b)
//				printf("rotate_b\n");
//			else if (head->command == rotate_both)
//				printf("rotate_both\n");
//			else if (head->command == reverse_a)
//				printf("reverse_a\n");
//			else if (head->command == reverse_b)
//				printf("reverse_b\n");
//			else if (head->command == reverse_both)
//				printf("reverse_both\n");
//			if (head->next)
//				head = head->next;
//			i++;
//		}
//		printf("end of stack\n");
//	}
//}

int			ft_check_sorted_list(t_stacks point)
{
	int		*array;
	int		i;
	int		ln;

	if (point.stack_b)
		return (0);
	ln = ft_check_lenght_of_stack(point.stack_a);
	array = ft_memalloc(ln * sizeof(int));
	i = 0;
	while (i < ln)
	{
		array[i++] = point.stack_a->num;
		point.stack_a = point.stack_a->next;
	}
	i = 0;
	while (i < ln - 1)
	{
		if (array[i] > array[i + 1])
		{
			free(array);
			return (0);
		}
		i++;
	}
	free(array);
	return (1);
}

int			main(int ac, char **av)
{
	t_stacks	point;

	ft_struct_zero(&point);
	if (!ft_parsing(&point, av, ac) || !ft_check_commands(&point))
	{
		printf("Error\n");
		ft_list_delete(&point);
		return (0);
	}
	ft_using_commands(&point);
	if (!ft_check_sorted_list(point))
		printf("KO\n");
	else
		printf("OK\n");
	ft_list_delete(&point);
	return (0);
}

