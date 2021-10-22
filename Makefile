NAME	= push_swap

SRCS	= align_stk.c condition_2.c condition.c condition_utils.c ft_instr_2.c ft_instr.c ft_stack_2.c ft_stack.c get_instr.c get_method.c get_method_utils.c get_stk_a.c get_stk_a_utils.c get_stk_b_2.c get_stk_b_3.c get_stk_b.c get_stk_b_utils.c main_push.c move_b_to_a.c move_b_to_a_utils_2.c move_b_to_a_utils.c utils.c

CHECKER	= main_checker.c checker.c

OBJS	= $(SRCS:.c=.o)

CC		= cc

AR		= ar rc

RM		= rm -rf

INC		= -I includes/

all:	$(NAME)

CFLAGS	= -Wall -Werror -Wextra

LIBFT	= Libft/libft.a

%.o: %.c
		$(CC) $(CLFAGS) $(INC) -o $@ -c $?

push:	$(OBJS)
		gcc $(CFLAGS) $(OBJS) $(LIBFT) -o push_swap

check:
		gcc $(CFLAGS) $(SRCS) $(CHECKER) $(LIBFT) -o checker

lib:	
	make -C Libft

$(NAME):	lib $(OBJS)
		gcc $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -no-pie

clean:
		$(RM) *.o
		make clean -C Libft

fclean:		clean
			$(RM) $(NAME)
			make fclean -C Libft

re:		fclean all

.PHONY:		all clean fclean re
