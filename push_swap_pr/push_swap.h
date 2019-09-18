/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:58:49 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/11 15:28:12 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/includes/libft.h"

typedef struct s_stack
{
	int					numb;
	int					op_b;
	int					op_a;
	int					num;
	struct s_stack		*next;
}	t_stack;

typedef struct s_stacks
{
	t_stack				*stack_a;
	t_stack				*stack_b;
} t_stacks;

void				ft_swap_stack(t_stack **stack);
void				ft_swap_both(t_stack **stack_a, t_stack **stack_b);
void				ft_push_stack(t_stack **src, t_stack **dst);
void				ft_rotate_stack(t_stack **head);
void				ft_rotate_all(t_stack **stack_a, t_stack **stack_b);
void				ft_reverse_rotate(t_stack **head);
void				ft_reverse_all(t_stack **stack_a, t_stack **stack_b);

void				ft_list_delete(t_stacks *point);
void				ft_stack_list_add(t_stack **stack, t_stack *new);
void				ft_struct_zero(t_stacks *point);
void				ft_print_stack(t_stack *stack, int ln);
int					ft_check_lenght_of_stack(t_stack *stack);

int					ft_parsing(t_stacks *point, char **str, int ac);
int					ft_check_repeats(t_stacks point);
int					ft_check_av(char *str);
int					ft_getting_numbers(t_stacks *point, char *str);
void				ft_sortof_array(int *array, int ln);


t_stack				*ft_listofstack_create(int a);
t_stacks			*ft_struct_create();

#endif
