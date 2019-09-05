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
	t_stacks *point;
	int			array[10] = {0,1,2,3,4,5,6,7,8,9};
	int			i;

	
	point = ft_struct_create();
	point->stack_a = ft_listofstack_create(array[0]);
	i = 1;
	while (i < 10)
		ft_stack_list_add(&point->stack_a, ft_listofstack_create(array[i++]));
	point->head = point->stack_a;
	ft_list_delete(point);
	printf("Hello, World!\n");
	return 0;
}