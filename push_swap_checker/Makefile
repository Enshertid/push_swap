# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 11:41:35 by ymanilow          #+#    #+#              #
#    Updated: 2019/09/10 12:20:33 by ymanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS_C = ./parsing.c\
		 ./checker.c\
		 ./list_functions.c\
		 ./useful_functions_forstack.c\
		 ./operations_for_bothstacks.c\
		 ./check_commands.c\
		 ./operations_for_singlestack.c

SRCS_CO = $(SRCS_C:.c=.o)\
			libft/*.o

all: $(NAME)

$(NAME):
	make -C ./libft/
	gcc -Wall -Werror -Wextra -Ichecker.h ./libft/libft.a $(SRCS_C) -o push_swap

clean:
	@make clean -C ./libft/
	@rm -f $(SRCS_O)

fclean: clean
	@make fclean -C ./libft/
	@rm -Rf ./push_swap
a: fclean all
	clear
	./push_swap 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
	./push_swap -50 -45 -2-4      55 67 9
	./push_swap hello error
	./push_swap     

c: clean
	clear
	@rm -Rf ./push_swap
	@rm -Rf ./push_swap.dSYM/
