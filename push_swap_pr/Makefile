# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 11:41:35 by ymanilow          #+#    #+#              #
#    Updated: 2019/10/05 17:35:48 by ymanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS_C = ./push_swap.c\
		 ./list_functions.c\
		 ./useful_functions_forstack.c\
		 ./operations_for_bothstacks.c\
		 ./operations_for_singlestack.c\
		 ./parsing.c\

SRCS_CO = $(SRCS_C:.c=.o)\
			libft/*.o

all: $(NAME)

$(NAME):
	@make -C ./ft_printf/
	@gcc -Wall -Werror -Wextra -Ipush_swap.h ./ft_printf/libftprintf.a $(SRCS_C) -o push_swap

clean:
	@make clean -C ./ft_printf/
	@rm -f $(SRCS_O)

fclean: clean
	@make fclean -C ./ft_printf/
	@rm -Rf ./push_swap
a: fclean all
	clear
	./push_swap

c: clean
	clear
	@rm -Rf ./push_swap
