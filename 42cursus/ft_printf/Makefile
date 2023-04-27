CC=gcc
CFLAGS=-Wall -Wextra -Werror -c
SRCS=	convert_c.c \
		convert_d_i.c \
		convert_p.c \
		convert_per.c \
		convert_s.c \
		convert_u.c \
		convert_x.c \
		ft_itoa.c \
		ft_memory_base.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putnbr_base.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_unsigned_itoa.c
OBJS=$(SRCS:.c=.o)
HEADER=./
NAME=libftprintf.a

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $^ -o $@ -I$(HEADER)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all