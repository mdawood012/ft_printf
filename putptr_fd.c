#include "ft_printf.h"
int    my_putptr_fd(void *s, int fd, int capital)
{
    int count;
    count = 0;
    if (s == NULL)
        return (count += my_putstr_fd("(nil)", fd));
    count += my_putstr_fd("0x", fd);
    unsigned long address = (unsigned long) s;
    count += long_to_hex(address, capital);
    return count;
}