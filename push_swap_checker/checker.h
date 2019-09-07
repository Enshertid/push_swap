/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:58:45 by ymanilow          #+#    #+#             */
/*   Updated: 2019/09/07 16:01:19 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

#include "libft/includes/libft.h"

typedef struct s_stack
{
	int					num;
	struct s_stack		*next;
}	t_stack;

typedef struct s_stacks
{
	t_stack *stack_a;
	t_stack *stack_b;
} t_stacks;

void				ft_list_delete(t_stacks *point);
void				ft_stack_list_add(t_stack **stack, t_stack *new);
void				ft_print_stack(t_stack *stack, int ln);
void				ft_struct_zero(t_stacks *point);
int					ft_check_lenght_of_stack(t_stack *stack);
int					ft_check_av(char *str);
t_stack				*ft_listofstack_create(int a);

void				ft_swap_stack(t_stack **stack);
void				ft_swap_both(t_stack **stack_a, t_stack **stack_b);
void				ft_push_stack(t_stack **src, t_stack **dst);
void				ft_rotate_stack(t_stack **head);
void				ft_rotate_all(t_stack **stack_a, t_stack **stack_b);
void				ft_reverse_rotate(t_stack **head);
void				ft_reverse_all(t_stack **stack_a, t_stack **stack_b);

void				ft_getting_numbers(t_stacks *point, char *str);
int					ft_parsing(t_stacks *point, char **str, int ac);

#endif //PUSH_SWAP_CHECKER_H
