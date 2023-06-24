NAME = philo
SRCS = philo.c \
	error_check.c \
	init_func.c \
	philo_behavior.c \
	philo_behavior_utils.c \
	philo_behavior_utils2.c \
	philo_start.c

OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = ./libft/libft.a

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@ 

$(NAME): $(OBJS) $(LIBFT)
	@./make.sh
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L ./libft -lft

$(LIBFT):
	@make -C ./libft all

clean:
	@${RM} ${OBJS}
	@make -C ./libft clean
	@echo "clean finished."

fclean:	clean
	@${RM} ${NAME}
	@make -C ./libft fclean
	@echo "include excuteable."

re:	
	@echo "\033[0;33mremake...\033[0m"
	@make fclean
	@make all

.PHONY: clean fclean re all