NAME = libft.a
SRCS = ft_split.c \
		ft_strncmp.c \
		ft_strjoin_libft.c \
		ft_strlen.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_substr.c \
		ft_isprint.c \
		ft_strdup.c \
		ft_strndup.c \
		ft_strchr_index.c \
		lst_utils.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_calloc.c \
		ft_memset.c \
		ft_bzero.c \
		ft_isalpha.c \
		ft_ascii_cmp.c

OBJS = ${SRCS:.c=.o}

OBJSALL = ${OBJS}

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
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