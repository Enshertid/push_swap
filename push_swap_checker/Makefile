# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanilow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 11:41:35 by ymanilow          #+#    #+#              #
#    Updated: 2019/09/06 17:41:47 by ymanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS_C = ./parsing.c\
		 ./checker.c\
		 ./list_functions.c\
		 ./useful_functions_forstack.c\
		 ./operations_for_bothstacks.c\
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
	./push_swap

c: clean
	clear
	@rm -Rf ./push_swap
