NAME = libft.a
SRCS = ft_split.c \
		ft_strncmp.c \
		ft_strjoin_libft.c \
		ft_strlen.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_substr.c
OBJS = ${SRCS:.c=.o}

OBJSALL = ${OBJS}

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

all: $(NAME)

%.o: %.c
	@echo "make object files..."
	@$(CC) $(CFLAGS) -c $^ -o $@ 

$(NAME): $(OBJSALL)
	@echo "make excutable files..."
	@ar -rc $@ $^

clean:
	@echo "remove object files except excutable files..."
	@${RM} ${OBJS}

fclean:	clean
	@echo "remove all object files and excutable files..."
	@${RM} ${NAME}

re:	
	@echo "remake files..."	
	@fclean all


.PHONY: clean fclean re all