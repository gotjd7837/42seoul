CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=	main.c\
		get_next_line.c\
		get_next_line_utils.c

OBJS=$(SRCS:.c=.o)
HEADER=./
LIBFT_DIR=./libft
MLX_DIR=./mlx
MFLAGS=-framework OpenGL -framework Appkit
NAME=so_long

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MFLAGS) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(HEADER)

clean :
	make -C $(LIBFT_DIR) clean
	rm -f $(MLX_DIR)/*.o
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(LIBFT_DIR)/libft.a
	rm -f $(MLX_DIR)/libmlx.a
	rm -f $(NAME)

re :
	make fclean
	make all