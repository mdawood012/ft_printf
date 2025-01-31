#include "ft_printf.h"

int handler_pointer(va_list list, int fd)
{
    return (my_putptr_fd(va_arg(list, void *), fd));
}

int    my_putptr_fd(void *s, int fd)
{
    int count;
    count = 0;
    if (s == NULL)
        return (count += my_putstr_fd("(nil)", fd));
    count += my_putstr_fd("0x", fd);
    unsigned long address = (unsigned long) s;
    count += long_to_hex(address, fd);
    return count;
}