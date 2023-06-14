CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=test.c

OBJS=$(SRCS:.c=.o)
HEADER=./include
LIBFT_DIR=./include/libft
NAME=push_swap

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(HEADER)

clean :
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean :
	make -C $(LIBFT_DIR) fclean
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all