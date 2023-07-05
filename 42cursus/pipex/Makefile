CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=
OBJS=$(SRCS:.c=.o)
HAEDER=./
LIBFT_DIR=./libft
NAME=pipex

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_DIR)/libft.a

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(HEADER)

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all