NAME = philo_bonus
CC = gcc -g
CCFLAGS = -Wall -Wextra -Werror 
# без этого флага не видит функции sem_open (не подключает библиотеку (Ubuntu)) -lpthread	
# без этого флага не видит функции sem_open (не подключает библиотеку (MACOS)) -lncurses	
PTHREAD_FLAGS = -lncurses	

INC = ./includes/

SRCS_DIR = srcs/

# ls srcs | awk ' {print $0}'
# ls srcs | awk 'BEGIN { ORS = "  "} {print $0}'
SRCS =	main.c\
		fork_watch.c	init.c	input.c		output.c	routine.c\
		ft_atoi.c	ft_itoa.c	ft_str.c


OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

#-----------------------------COLORS----------------------------------------------
R = \033[1;31m
G = \033[0;32m
B = \033[0;34m
C = \033[0;36m
P = \033[0;35m
Y = \033[0;33m
GR = \033[30;1m
DF = \033[0m
#---------------------------------------------------------------------------------

all: subdir $(NAME)
	@echo "$(B)----------  BONUS PART  ---------- $(DF)"
	@echo "$(G)\t./[program_name] $(Y)[required argument]  $(GR)[optional argument]"
	@echo "$(B)---------------------------------- $(DF)"
	@echo "\t$(G)./$(NAME)$(DF) $(Y)[n_of_philos] [time_to_die] [time_to_eat] [time_to_sleep] $(GR)[count_of_meals=optional] $(DF)"

subdir:
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) -I $(INC) $(OBJS) -o $(NAME) $(PTHREAD_FLAGS)

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
