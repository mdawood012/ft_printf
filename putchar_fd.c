#include "ft_printf.h"

int	my_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
    return (1);
}