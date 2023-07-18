CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=	main.c\
		set_info.c\
		print_error.c\
		info_free.c\
		find_cmd_abspath.c
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
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(HAEDER)

clean :
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean :
	make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS) $(NAME)

re :
	make fclean
	make all