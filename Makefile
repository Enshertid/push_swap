# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 15:21:12 by ymanilow          #+#    #+#              #
#    Updated: 2019/10/11 17:45:43 by ymanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

CHECKER = checker

SRCS_C_CHECKER = ./checker_dir/checker.c\
				./checker_dir/parsing_checker.c\
				./checker_dir/list_functions_checker.c\
				./checker_dir/useful_functions_forstack_checker.c\
				./checker_dir/operations_for_bothstacks_checker.c\
				./checker_dir/check_commands.c\
				./checker_dir/operations_for_singlestack_checker.c\
				./checker_dir/bonuses_checker.c

SRCS_C_PUSH_SWAP =	./program/push_swap.c\
					./program/list_functions.c\
		 			./program/useful_functions_forstack.c\
				 	./program/operations_for_bothstacks.c\
					./program/operations_for_singlestack.c\
					./program/functions_for_operations.c\
					./program/parsing.c\
					./program/check_op.c\
					./program/filling_op_point.c\
					./program/pre_sort_stacks.c\
					./program/use_operations.c\
					./program/sort_array.c\
					./program/sort_stack_pr.c\
					./program/bonuses.c\
					./program/output_of_operations_pr.c

SRCS_O_CHECKER = $(SRCS_C_CHECKER:.c=.o)

SRCS_O_PUSH_SWAP = $(SRCS_C_PUSH_SWAP:.c=.o)

all: $(PUSH_SWAP) $(CHECKER)

%.o_pu: program/%.c
	@gcc -Wall -Wextra -Werror -c $(SRCS_C_PUSH_SWAP)

%.o: checker_dir/%.c
	@gcc -Wall -Wextra -Werror -c $(SRCS_C_CHECKER)

$(PUSH_SWAP): $(SRCS_O_PUSH_SWAP)
	@make -C ./ft_printf/
	@gcc -Wall -Wextra -Werror -I./program/push_swap.h ./ft_printf/libftprintf.a $(SRCS_O_PUSH_SWAP) -o push_swap

$(CHECKER): $(SRCS_O_CHECKER)
	@make -C ./ft_printf/
	@gcc -Wall -Wextra -Werror -Ichecker/checker.h ./ft_printf/libftprintf.a $(SRCS_O_CHECKER) -o checker

clean :
	@make clean -C ./ft_printf/
	@rm -Rf $(SRCS_O_CHECKER)
	@rm -Rf $(SRCS_O_PUSH_SWAP)
	@rm -Rf ./push_swap.dSYM/
	@rm -Rf ./checker.dSYM/

fclean : clean
	@make fclean -C ./ft_printf/
	@rm -Rf ./checker
	@rm -Rf ./push_swap

re : fclean all

