/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanilow <ymanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:58:45 by ymanilow          #+#    #+#             */
/*   Updated: 2019/10/12 15:00:15 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../ft_printf/ft_printf.h"

enum	e_commands
{
	push_a,
	push_b,
	swap_a,
	swap_b,
	swap_both,
	rotate_a,
	rotate_b,
	rotate_both,
	reverse_a,
	reverse_b,
	reverse_both
};

typedef struct		s_stack
{
	int					num;
	struct s_stack		*next;
}					t_stack;

typedef struct		s_command
{
	enum e_commands		command;
	struct s_command	*next;
}					t_command;

typedef struct		s_stacks
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_command		*commands;
	t_command		*head;
	int					color;
	int					comands;
	int					op;
	int					debugger;
}					t_stacks;

int					ft_check_first_ac(t_stacks *point, char *str);
void				ft_usage(void);
void				ft_error(t_stacks *point);
int					ft_check_sorted_list(t_stacks point);

void				*ft_list_create(int a, int type, char *ln);
void				ft_list_of_command_add(t_command **head, t_command *new);
void				ft_list_delete(t_stacks *point);
void				ft_stack_list_add(t_stack **stack, t_stack *new);

void				ft_struct_zero(t_stacks *point);
void				ft_sortof_array(int *array, int ln);
int					ft_check_lenght_of_stack(t_stack *stack);

void				ft_swap_stack(t_stack **stack, t_stacks *point, int solo);
void				ft_push_stack(t_stack **src, t_stack **dst,
					t_stacks *point);
void				ft_rotate_stack(t_stack **head, t_stacks *point,
					int type);
void				ft_reverse_rotate(t_stack **head, t_stacks *point,
					int solo);

void				ft_swap_both(t_stack **stack_a,
					t_stack **stack_b, t_stacks *point);
void				ft_rotate_all(t_stack **stack_a,
					t_stack **stack_b, t_stacks *point);
void				ft_reverse_all(t_stack **stack_a,
					t_stack **stack_b, t_stacks *point);

int					ft_isonly_spaces(char *str);

int					ft_getting_numbers(t_stacks *point, char *str);
void				ft_using_commands(t_stacks *point);
int					ft_parsing(t_stacks *point, char **str, int ac);
int					ft_command_add(char *ln, t_command *new);
int					ft_check_commands(t_stacks *point);
int					ft_check_av(char *str);
int					ft_check_repeats(t_stacks point);

#endif
