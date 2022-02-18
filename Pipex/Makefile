NAME = pipex

SRCS =			ft_pipex.c			ft_strlen.c\
				ft_strlcpy.c		ft_strnstr.c\
				ft_substr.c			ft_strjoin.c\
				ft_split.c


HEADER	=	.
OBJ		=	$(SRCS:%.c=%.o)

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -g -I$(HEADER)

.PHONY: all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $@
%.o		:	%.c	$(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all 
