CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft
SRCS = printf.c main.c
OBJS = $(SRCS:.c=.o)
DEPS = libftprintf.h
NAME = libftprintf.a
LIB = ar rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
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

