NAME = libft.a
SRCS = ft_atoi.c 

OBJS = ${SRCS:.c=.o}

OBJSALL = ${OBJS}

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@ 

$(NAME): $(OBJSALL)
	@ar -rc $@ $^

clean:
	@${RM} ${OBJS}

fclean:	clean
	@${RM} ${NAME}

re:	
	@fclean all


.PHONY: clean fclean re all