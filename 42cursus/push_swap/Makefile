CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=test.c

OBJS=$(SRCS:.c=.o)
NAME=push_swap

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $@ $^ -L./libft

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I./

clean :
	make -C ./libft clean
	rm -f $(OBJS)

fclean :
	make -C ./libft fclean
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all