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
	@$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	@ar -rc $@ $^

clean:
	@${RM} ${OBJS} ${BONUSOBJS}

fclean:	clean
	@${RM} ${NAME}

re:		
	@make fclean
	@make all

.PHONY: clean fclean re all