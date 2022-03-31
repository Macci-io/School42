# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 20:56:23 by snicky            #+#    #+#              #
#    Updated: 2021/11/01 19:29:20 by snicky           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	libftprintf.a

SRCS 	=	ft_printf.c\
			utils/ft_putchar.c\
			utils/ft_putstr.c\
			utils/ft_put_uns.c\
			utils/ft_put_x.c\
			utils/ft_put_p.c\
			utils/ft_put_di.c\
			utils/ft_putchar_fd.c

HEADER	=	ft_printf.h 
OBJ		=	$(SRCS:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY: all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o		:	%.c	$(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ) $(OBJ_B)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all 
