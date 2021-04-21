SRCS	= ft_instr*.c ft_stack*.c get_instr.c get_stk_a.c get_stk_b*.c get_method.c align_stk.c condition*.c get_method_utils.c get_stk_a_utils.c move_b_to_a*.c utils.c

PUSH	= main_push.c

CHECKER	= main_checker.c checker.c

OBJS	= $(SRCS:.c=.o)

CC		= cc

AR		= ar rc

RM		= rm -rf

CFLAGS	= -Wall -Werror -Wextra

LIBFT	= Libft/libft.a

%.o: %.c
		$(CC) $(CLFAGS) -o $@ -c $?

push:
		gcc $(CFLAGS) $(SRCS) $(PUSH) $(LIBFT) -o push_swap

check:
		gcc $(CFLAGS) $(SRCS) $(CHECKER) $(LIBFT) -o checker

all:
		gcc $(CFLAGS) $(SRCS) $(LIBFT)

clean:
		$(RM) *.o
