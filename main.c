/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:58:49 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/04 11:33:21 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
	t_stack		*head;
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			array[10] = {0,1,2,3,4,5,6,7,8,9};
	int			i;

	stack_b = NULL;
	stack_a = ft_list_create(array[0]);
	i = 1;
	while (i < 10)
		ft_list_add(&stack_a, ft_list_create(array[i++]));
	head = stack_a;
	ft_print_list(stack_a, ft_check_lenght_of_list(stack_a));
	ft_print_list(stack_b, ft_check_lenght_of_list(stack_b));
	ft_list_delete(head);
	printf("Hello, World!\n");
	return 0;
}