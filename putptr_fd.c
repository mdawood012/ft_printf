#include "ft_printf.h"

int    my_putptr_fd(char *s, int fd, int capital)
{
    int count;
    long address = (long)s;
    my_putchar_fd('0', fd);
    my_putchar_fd('x', fd);
    count = long_to_hex(address, capital) + 2;
    return count;
}