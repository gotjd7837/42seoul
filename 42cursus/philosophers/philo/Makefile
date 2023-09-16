CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=	main_trd.c\
		main.c\
		print_msg.c\
		set_data.c\
		set_philo.c\
		start_eat.c\
		start.c\
		util.c\

OBJS=$(SRCS:.c=.o)
HEADER=./
NAME=philo

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

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