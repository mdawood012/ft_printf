#include "ft_printf.h"

int   long_to_hex(unsigned long num, int fd)
{
    char *hex_values;
    char values[20];
    int i;
    int count; 
    int remainder;

    hex_values = "0123456789abcdef";
    count = 0;
	i = 0;
	if (num == 0)
        count += my_putchar_fd('0', fd);
    while (num > 0)
    {
        remainder = num % 16;
        values[i++] = hex_values[remainder];
        num/=16;
    }
    while (i > 0)
        count += my_putchar_fd(values[--i], fd);
    return count;
}

