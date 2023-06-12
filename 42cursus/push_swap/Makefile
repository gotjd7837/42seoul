CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=test.c

OBJS=$(SRCS:.c=.o)
HEADER=./include
LIBFT_DIR=./libft
NAME=push_swap

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $@ $^ -L.$(LIBFT_DIR) -lft

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(HEADER)

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