NAME = push_swap
BONUSNAME = checker
SRCS = a_to_b.c \
	b_to_a.c \
	b_to_a2.c \
	error_check.c \
	ft_atoi.c \
	ft_lst_location.c \
	ft_lstclear.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_split.c \
	main.c \
	operate_push.c \
	operate_rev_rotate.c \
	operate_rotate.c \
	operate_swap.c \
	operation_comb.c \
	print_push.c \
	print_rev_rotate.c \
	print_rotate.c \
	print_swap.c \
	sorting_small_argc.c \
	utils.c \
	main_utils.c \
	main_utils2.c
BONUSSRC = main_bonus.c \
	run_operations_bonus.c \
	main_utils.c \
	main_utils2.c \
	operate_push.c \
	operate_rev_rotate.c \
	operate_rotate.c \
	operate_swap.c \
	print_push.c \
	print_rev_rotate.c \
	print_rotate.c \
	print_swap.c \
	utils.c \
	error_check.c \
	ft_atoi.c \
	ft_lst_location.c \
	ft_lstclear.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_split.c \
	ft_strlen.c \
	ft_strncmp.c \
	sorting_small_argc.c \
	operation_comb.c \
	get_next_line_utils.c \
	get_next_line.c

OBJS = ${SRCS:.c=.o}
BONUSOBJS = ${BONUSSRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

bonus: $(BONUSNAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUSNAME): $(BONUSOBJS)
	$(CC) $(CFLAGS) $(BONUSOBJS) -o $(BONUSNAME)

clean:
		${RM} ${OBJS} ${BONUSOBJS}

fclean:	clean
		${RM} ${NAME} ${BONUSNAME}

re:		
		make fclean
		make all bonus

.PHONY: clean fclean re all bonus