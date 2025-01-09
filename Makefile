CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft
SRCS = printf.c
OBJS = $(SRCS:.c=.o)
DEPS = libftprintf.h
NAME = libftprintf.a
LIB = ar rcs
RM = rm -f

LIBFT = ./libft

libft_makefile:
	$(MAKE) -C libft

all: $(NAME) libft_makefile

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)
	$(CC) $(CFLAGS) -L$(LIBFT) -lft -o $(NAME)
	
%.o: %.c $(DEPS)
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT)

re: fclean all

.PHONY : all clean fclean re libft_makefile

