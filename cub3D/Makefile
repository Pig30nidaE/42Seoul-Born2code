NAME = cub3D

INC = $(MandatoryDir)/cub3D.h
FRAMEWORK	= -framework AppKit -framework OpenGL

MandatoryDir = ./Mandatory/
ParsingDir = $(MandatoryDir)parsing/
ExceptionHandlingDir = $(MandatoryDir)exception_handling/
LibftDir = ./libft/
GnlDir = ./get_next_line/
MlxDir = ./minilibx/
ExcutingDir = $(MandatoryDir)excuting/

SRCS = $(ExceptionHandlingDir)check_args.c \
	$(ExceptionHandlingDir)check_fd.c \
	$(ExceptionHandlingDir)check_file_path.c \
	$(ExceptionHandlingDir)check_rgb_color.c \
	$(ExceptionHandlingDir)error_print.c \
	$(ExceptionHandlingDir)check_map.c \
	$(ParsingDir)parsing.c \
	$(ParsingDir)parsing_utils.c \
	$(ParsingDir)parsing_functions.c \
	$(ParsingDir)parsing_functions2.c \
	$(MandatoryDir)main.c \
	$(GnlDir)get_next_line_bonus.c \
	$(GnlDir)get_next_line_utils_bonus.c \
	$(ExcutingDir)excuting.c \
	$(ExcutingDir)draw.c\
	$(ExcutingDir)key_hook.c\
	$(ExcutingDir)raycasting.c\
	$(ExcutingDir)frame_rendering.c\
	$(ExcutingDir)player_init.c\
	$(ExcutingDir)hook_command.c\
	$(ExcutingDir)mlx_struct_init.c\
	$(ExcutingDir)texture_init.c\

OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = $(LibftDir)libft.a

MLX = $(MlxDir)libmlx.a

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@ -I $(INC)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "making..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(LibftDir) -lft -L ./minilibx/ -lmlx $(FRAMEWORK)

$(LIBFT):
	@make -C $(LibftDir) all

$(MLX):
	@make -C $(MlxDir) all

clean:
	@${RM} ${OBJS} ${BONUSOBJS}
	@make -C $(LibftDir) clean
	@make -C $(MlxDir) clean
	@echo "clean finished."

fclean:	clean
	@${RM} ${NAME} ${BONUSNAME}
	@make -C $(LibftDir) fclean
	@echo "include excutable."

re:	
	@echo "\033[0;33mremake...\033[0m"
	@make fclean
	@make all

.PHONY: clean fclean re all