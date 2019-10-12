/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:58:49 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 11:37:48 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"

typedef struct		s_stack
{
	int					op_b;
	int					op_a;
	int					op;
	int					num;
	struct s_stack		*next;
}					t_stack;

typedef struct		s_stacks
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	int					fd;
	int					color;
	int					commands;
	int					debugger;
}					t_stacks;

typedef struct		s_lst
{
	int					*array;
	int					max_stack;
	int					min_stack;
	int					numb_of_first;
	int					numb_of_second;
}					t_lst;

void				ft_swap_stack(t_stack **stack, int type, t_stacks *point);
void				ft_push_stack(t_stack **src, t_stack **dst,
					int type, t_stacks *point);
void				ft_rotate_stack(t_stack **head,
					int type, int solo, t_stacks *point);
void				ft_reverse_rotate(t_stack **head,
					int type, int solo, t_stacks *point);

void				ft_swap_both(t_stack **stack_a,
					t_stack **stack_b, t_stacks *point);
void				ft_rotate_all(t_stack **stack_a,
					t_stack **stack_b, t_stacks *point);
void				ft_reverse_all(t_stack **stack_a,
					t_stack **stack_b, t_stacks *point);

void				ft_list_delete(t_stacks *point);
void				ft_stack_list_add(t_stack **head, t_stack *new);
void				ft_struct_zero(t_stacks *point, t_lst *pre_sort);
int					ft_check_lenght_of_stack(t_stack *stack);

int					ft_parsing(t_stacks *point, char **str, int ac,
					t_lst *pre_sort);
int					ft_check_repeats(t_stacks point);
int					ft_check_av(char *str);
int					ft_getting_numbers(t_stacks *point, char *str);

void				ft_sort_of_stack(t_stacks *point, t_lst *pre_sort);
void				ft_sortof_array(int *array, int ln);
void				ft_usage(void);
void				ft_debugger(t_stacks *point);
void				ft_out_rotate(int type, int solo, t_stacks *point);
void				ft_output_ofpush(int type, t_stacks *point);

void				ft_pre_sort(t_lst *pre, t_stacks *point);
void				ft_get_op_b(t_stack **stack);
void				ft_get_op_a(t_stacks *point);
void				ft_check_side(t_stacks *point, int gap, t_stack *tmp_b);
void				ft_check_middle(t_stacks *point, int gap, t_stack *tmp_b);

int					ft_synchrone(int num1, int num2);
int					ft_check_without_synchrone(t_stack *tmp);
int					ft_check_with_synchrone(t_stack *tmp);
int					ft_mod_num(int num);
int					ft_check_first_ac(t_stacks *point, char *str);

int					ft_is_gap(t_stack *stack);
void				ft_use_op(t_stacks *point);
void				ft_use_operation(t_stack *tmp, t_stacks *point);
void				ft_use_rotate(t_stacks *point, int op_a, int op_b);
void				ft_use_reverse_rotate(t_stacks *point, int op_a,
					int op_b);

t_stack				*ft_listofstack_create(int a);

void				ft_count_commands(t_stacks *point);

#endif
