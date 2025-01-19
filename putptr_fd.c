#include "libftprintf.h"

int    ft_putptr_fd(char *s, int fd, int capital)
{
    int count;
    long address = (long)s;
    ft_putchar_fd('0', fd);
    ft_putchar_fd('x', fd);
    count = long_to_hex(address, capital) + 2;
    return count;
}