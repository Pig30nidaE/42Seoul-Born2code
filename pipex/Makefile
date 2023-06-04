NAME = pipex
SRCS = ./get_next_line/get_next_line_utils.c \
		./get_next_line/get_next_line.c \
		./Mandatory/main.c \
		./Mandatory/print_error.c \
		./Mandatory/print_error2.c \
		./Mandatory/error_check.c \
		./Mandatory/parsing.c \
		./Mandatory/proc_control.c
BONUSSRC = ./get_next_line/get_next_line_utils.c \
		./get_next_line/get_next_line.c \
		./Bonus/error_check_bonus.c \
		./Bonus/main_bonus.c \
		./Bonus/parsing_bonus.c \
		./Bonus/print_error_bonus.c \
		./Bonus/print_error2_bonus.c \
		./Bonus/proc_control_bonus.c \
		./Bonus/proc_flow_bonus.c

OBJS = ${SRCS:.c=.o}
BONUSOBJS = ${BONUSSRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./libft/libft.a
MAKESTR = "success make"
BONUS_MAKESTR = "success make (bonus)"

ifdef BONUSFLAG
	STR = $(BONUS_MAKESTR)
	OBJSALL = ${BONUSOBJS}
else
	STR = $(MAKESTR)
	OBJSALL = ${OBJS}
endif

all: $(NAME)


%.o: %.c
	@echo "make object files..."
	@$(CC) $(CFLAGS) -c $^ -o $@ 

$(NAME): $(OBJSALL) $(PRINTF) $(LIBFT)
	@echo "make excutable files..."
	@$(CC) $(CFLAGS) $(OBJSALL) -o $(NAME) -L ./ft_printf -lftprintf -L ./libft -lft
	@echo "\033[32m"
	@echo $(STR)


$(PRINTF):
	@make -C ./ft_printf all

$(LIBFT):
	@make -C ./libft all

bonus: 
	@make BONUSFLAG=1 all

clean:
	@echo "remove object files except excutable files..."
	@${RM} ${OBJS} ${BONUSOBJS}
	@make -C ./ft_printf clean
	@make -C ./libft clean

fclean:	clean
	@echo "remove all object files and excutable files..."
	@${RM} ${NAME}
	@make -C ./ft_printf fclean
	@make -C ./libft fclean


re:	
	@echo "remake files..."
	@make fclean
	@make all bonus

.PHONY: clean fclean re all bonus