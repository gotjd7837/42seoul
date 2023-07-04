CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=
OBJS=$(SRCS:.c=.o)
HAEDER=./
NAME=pipex

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -I$(HAEDER)

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