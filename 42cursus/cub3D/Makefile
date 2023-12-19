# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haekang <haekang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 19:47:46 by haekang           #+#    #+#              #
#    Updated: 2023/12/19 16:25:24 by haekang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MFLAGS=-framework OpenGL -framework Appkit
NAME = cub3D
HEADERS = ./includes
MLX_DIR = ./includes/mlx
SRCS = $(wildcard sources/*/*.c)
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(MFLAGS) $(OBJS) $(MLX_DIR)/libmlx.a -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -Rf $(OBJS)

fclean: clean
	rm -Rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re