CC=gcc
CFLAGS=-Wall -Wextra -Werror -c
SRCS=	ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd \
		ft_putnbr_fd.c
SRCS_B=	ft_lstnew.c \
		ft_lstadd_front.c \

OBJS=$(SRCS:.c=.o)
OBJS_B=$(SRCS_B:.c=.o)
HEADER=libft.h
NAME=libft.a

.PHONY: all clean fclean bonus re

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

bonus : $(OBJS) $(OBJS_B)
	ar rcs $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) $^ -o $@ -I$(HEADER)

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all