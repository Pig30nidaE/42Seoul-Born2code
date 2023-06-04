NAME = minishell
SRCS = ./Mandatory/execute/builtin_func.c \
	./Mandatory/execute/builtin_func2.c \
	./Mandatory/execute/builtin_func_utils.c \
	./Mandatory/execute/run_prompt.c \
	./Mandatory/execute/proc_control.c \
	./Mandatory/execute/proc_control_utils.c \
	./Mandatory/execute/stream_control.c \
	./Mandatory/execute/stream_control2.c \
	./Mandatory/execute/stream_control_file.c \
	./Mandatory/execute/print_error_utils.c \
	./Mandatory/execute/print_error.c \
	./Mandatory/execute/print_error2.c \
	./Mandatory/execute/error_check.c \
	./Mandatory/parse/env_set.c \
	./Mandatory/parse/env_utils.c \
	./Mandatory/parse/env_utils2.c \
	./Mandatory/parse/get_two_array_env.c \
	./Mandatory/parse/box_utils.c \
	./Mandatory/parse/input_split.c \
	./Mandatory/parse/input_split_utils.c \
	./Mandatory/parse/token_syntax_alaysis.c \
	./Mandatory/parse/token_syntax_alaysis_utils.c \
	./Mandatory/parse/replace_dollar.c \
	./Mandatory/parse/replace_dollar2.c \
	./Mandatory/parse/heredoc_dollar.c \
	./Mandatory/parse/exe_utils.c \
	./Mandatory/parse/cut_quote.c \
	./Mandatory/parse/redirect_to_exe.c \
	./Mandatory/parse/cmd_args_to_exe.c \
	./Mandatory/parse/parsing.c \
	./Mandatory/parse/set_signal.c \
	./Mandatory/parse/set_term.c \
	./Mandatory/parse/free.c \
	./Mandatory/parse/free_utils.c \
	./Mandatory/execute/main.c

OBJS = ${SRCS:.c=.o}
BONUSOBJS = ${BONUSSRC:.c=.o}
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
COMFILE_FLAGS = -lreadline -L/Users/sanghyol/.brew/opt/readline/lib
OBJ_FLAGS = -I/Users/sanghyol/.brew/opt/readline/include
RM = rm -rf
PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./libft/libft.a

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(OBJ_FLAGS) -c $^ -o $@ 

$(NAME): $(OBJS) $(PRINTF) $(LIBFT)
	@./make.sh
	@$(CC) $(CFLAGS) $(COMFILE_FLAGS) $(OBJ_FLAGS) $(OBJS) -o $(NAME) -L ./ft_printf -lftprintf -L ./libft -lft

$(PRINTF):
	@make -C ./ft_printf all

$(LIBFT):
	@make -C ./libft all

bonus: 
	@make BONUSFLAG=1 all

clean:
	@${RM} ${OBJS}
	@make -C ./ft_printf clean
	@make -C ./libft clean
	@echo "clean finished."

fclean:	clean
	@${RM} ${NAME}
	@make -C ./ft_printf fclean
	@make -C ./libft fclean
	@echo "include excutable."

re:	
	@echo "\033[0;33mremake...\033[0m"
	@make fclean
	@make all

.PHONY: clean fclean re all bonus