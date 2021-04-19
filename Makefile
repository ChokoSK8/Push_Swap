SRCS	= ft_instr.c ft_stack.c get_instr.c main.c utils.c get_stk_a.c get_stk_b.c get_method.c align_stk.c move_b_to_a.c condition.c condition_utils.c get_stk_b_utils.c get_method_utils.c get_stk_a_utils.c move_b_to_a_utils.c

OBJS	= $(SRCS:.c=.o)

CC		= cc

AR		= ar rc

RM		= rm -rf

CFLAGS	= -Wall -Werror -Wextra

LIBFT	= Libft/libft.a

%.o: %.c
		$(CC) $(CLFAGS) -o $@ -c $?

all:
		gcc $(CFLAGS) $(SRCS) $(LIBFT)

clean:
		$(RM) *.o
