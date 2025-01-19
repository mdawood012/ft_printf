CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft
SRCS = ft_printf.c long_to_hex.c nbrthex_fd.c putchar_fd.c putnbr_fd.c putptr_fd.c putstr_fd.c putuinbr_fd.c
OBJS = $(SRCS:.c=.o)
DEPS = ft_printf.h
NAME = libftprintf.a
LIB = ar rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME):$(LIBFT) $(OBJS)
	$(LIB) $(NAME) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY : all clean fclean re

