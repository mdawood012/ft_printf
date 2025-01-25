CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft
SRCS = ft_printf.c long_to_hex.c putchar_fd.c putnbr_fd.c putptr_fd.c putstr_fd.c putuinbr_fd.c
OBJS = $(SRCS:.c=.o)
DEPS = ft_printf.h
NAME = libftprintf.a
LIB = ar rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_OBJS = $(addprefix $(LIBFT_DIR)/, ft_atoi.o ft_itoa.o ft_putnbr_fd.o ft_strlcpy.o ft_tolower.o ft_bzero.o ft_memchr.o ft_putstr_fd.o ft_strlen.o ft_toupper.o ft_calloc.o ft_memcmp.o ft_split.o ft_strmapi.o ft_isalnum.o ft_memcpy.o ft_strchr.o ft_strncmp.o ft_isalpha.o ft_memmove.o ft_strdup.o ft_strnstr.o ft_isascii.o ft_memset.o ft_striteri.o ft_strrchr.o ft_isdigit.o ft_putchar_fd.o ft_strjoin.o ft_strtrim.o ft_isprint.o ft_putendl_fd.o ft_strlcat.o ft_substr.o) 

all: $(NAME)

$(NAME):$(LIBFT) $(OBJS)
	$(LIB) $(NAME) $(OBJS) $(LIBFT_OBJS)

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
