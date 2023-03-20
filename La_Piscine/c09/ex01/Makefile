CC=gcc
CFLAGS=-Wall -Wextra -Werror -c
SRCS=srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJS=srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strcmp.o srcs/ft_strlen.o srcs/ft_swap.o
HEADER=includes
NAME=libft.a

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $^ -o $@ -I$(HEADER)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all