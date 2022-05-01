NAME = philo
CC = gcc -g
CCFLAGS = -Wall -Wextra -Werror

INC = ./includes/

SRCS_DIR = srcs/

# ls srcs | awk ' {print $0}'
# ls srcs | awk 'BEGIN { ORS = "  "} {print $0}'
SRCS =	ft_atoi.c		ft_itoa.c		ft_str.c	input.c\
		main.c			init.c			free.c		output.c	actions.c\
		threads.c		threads_routine.c			threads_routine2.c

OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

#---------------------------------------------------------------------------------
R = \033[1;31m
G = \033[0;32m
B = \033[0;34m
C = \033[0;36m
P = \033[0;35m
DF = \033[0m
#---------------------------------------------------------------------------------

all: subdir $(NAME)
	@echo "$(G)----- ./$(NAME) is ready -----$(DF)"

subdir:
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -I $(INC) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CCFLAGS) -I $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	clear
	@echo "$(P)----- All OBJS deleted -----$(DF)"

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	clear
	@echo "$(R)----- All created files deleted -----$(DF)"

re: fclean all

bonus:

norm:
	norminette $(SRCS_DIR)
	norminette $(INC)

.PHONY: clean fclean re bonus
