NAME = libftprintf.a
SRCS = ft_print_hex.c \
		ft_print_memory.c \
		ft_print_str.c \
		ft_printf.c \
		ft_putchr.c \
		ft_putnbr.c

OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

%.o: %.c
	@echo "make object files..."
	@$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	@echo "make excutable files..."
	@ar -rc $@ $^

clean:
	@echo "remove object files except excutable files..."
	@${RM} ${OBJS} ${BONUSOBJS}

fclean:	clean
	@echo "remove all object files and excutable files..."
	@${RM} ${NAME}

re:		
	@echo "remake files..."
	@make fclean
	@make all

.PHONY: clean fclean re all