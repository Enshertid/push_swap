/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:58:49 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/04 10:11:06 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/includes/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int					num;
	struct s_stack	*next;
}	t_stack;

void				ft_list_delete(t_stack *head);
void				ft_list_add(t_stack **stack, t_stack *new);
void				ft_print_list(t_stack *stack, int ln);
void				ft_swap_onestack(t_stack **stack);
void				ft_push_stack(t_stack **stack_a, t_stack **stack_b);
int					ft_check_lenght_of_list(t_stack *stack);
t_stack				*ft_list_create(int a);


#endif
