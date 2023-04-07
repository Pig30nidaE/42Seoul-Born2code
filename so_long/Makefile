NAME = so_long
SRCS = ./Mandatory/dfs.c \
		./Mandatory/error_exit.c \
		./Mandatory/exception_handling.c \
		./Mandatory/main_utils.c \
		./Mandatory/main.c \
		./Mandatory/map_parsing.c \
		./Mandatory/free_func.c \
		./Mandatory/run_mlx.c \
		./Mandatory/run_img.c \
		./Mandatory/run_hook.c \
		./Mandatory/change_map.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./libft/ft_memcpy.c

OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

all: libpf libmlx $(NAME)

%.o: %.c
	@echo "make object files..."
	@$(CC) $(CFLAGS) -c $^ -o $@


$(NAME): $(OBJS)
	@echo "make excutable files..."
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) -o $(NAME) -L ./mlx -lmlx -L ./ft_printf -lftprintf
	@echo "\033[32m"
	@echo "make success."

libpf:
	make -C ./ft_printf all

libmlx:
	make -C ./mlx all

clean:
	@echo "remove object files except excutable files..."
	@${RM} ${OBJS}
	@make -C ./ft_printf clean
	@make -C ./mlx clean

fclean:	clean
	@echo "remove all object files and excutable files..."
	@${RM} ${NAME}
	@make -C ./ft_printf fclean
	@make -C ./mlx clean

re:	
	@echo "remake files..."
	@make fclean
	@make all

.PHONY: clean fclean re all