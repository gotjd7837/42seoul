CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=	main.c\
		get_next_line.c\
		set_info.c\
		draw.c\
		key_press.c\
		press_red_button.c\
		handle_err_map_data.c\
		print_and_exit.c\
		check_valid_path.c\
		draw_item.c\

OBJS=$(SRCS:.c=.o)
HEADER=./includes
LIBFT_DIR=./includes/libft
PRINTF_DIR=./includes/ft_printf
MLX_DIR=./includes/mlx
MFLAGS=-framework OpenGL -framework Appkit
NAME=so_long

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(MFLAGS) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a $(MLX_DIR)/libmlx.a -o $@ $^

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $^ -I$(HEADER)

clean :
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(LIBFT_DIR)/libft.a
	rm -f $(PRINTF_DIR)/libftprintf.a
	rm -f $(MLX_DIR)/libmlx.a
	rm -f $(NAME)

re :
	make fclean
	make all