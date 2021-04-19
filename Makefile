SRCS	= ft_instr.c ft_stack.c get_instr.c main.c

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
