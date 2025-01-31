#include "ft_printf.h"

int handler_char(va_list list, int fd) 
{
    return (my_putchar_fd(va_arg(list, int), fd));
}

int	my_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
    	return (1);
}
