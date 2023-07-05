CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=	arg_parsing.c\
		count_ra.c\
		first_sort_stack.c\
		handle_arg_error.c\
		hard_coding.c\
		instr_push.c\
		instr_rev_rotate.c\
		instr_rotate.c\
		instr_swap.c\
		main.c\
		new_node.c\
		print_error.c\
		quick_sort_arr.c\
		rr_a_b.c\
		sort_stack.c\
		stack.c\
		second_sort_stack.c\

OBJS=$(SRCS:.c=.o)
HEADER=./include
LIBFT_DIR=./include/libft
NAME=push_swap

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_DIR)/libft.a

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