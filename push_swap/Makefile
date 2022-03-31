# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicky <snicky@student.42.ru>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 17:05:15 by awarren           #+#    #+#              #
#    Updated: 2022/01/21 23:49:12 by snicky           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	source/checkings.c \
			source/moves_I.c \
			source/moves_II.c \
			source/push_swap.c \
			source/radix_sort.c \
			source/small_sort.c \
			source/steps.c

OBJ		=	${SRC:.c=.o}

INCD	=	includes/push_swap.h

NAME	=	push_swap

MODULE	=	./libft/libft.a

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

CC		=	clang

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	

all:			$(NAME)

$(NAME):	$(MODULE) $(OBJ) $(INCD)
	$(CC) $(CFLAGS) $(OBJ) $(MODULE) -o $(NAME)
$(MODULE):
	make -C libft

clean:
	$(RM) $(OBJ)
	make clean -C libft

fclean:		clean
	$(RM) $(NAME)
	make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re 
