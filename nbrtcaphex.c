#include "ft_printf.h"

int handler_hex_upper(va_list list, int fd)
{
    return (ft_toupper(long_to_hex(va_arg(list, unsigned long), fd)));
}