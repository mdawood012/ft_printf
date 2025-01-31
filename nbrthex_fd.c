#include "ft_printf.h"

int handler_hex(va_list list, int fd)
{
    return (long_to_hex(va_arg(list, unsigned long), fd));
}
