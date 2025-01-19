#include "libftprintf.h"

int   long_to_hex(long num, int capital)
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
        return 0;
    while (num > 0)
    {
        remainder = num % 16;
	    values[i++] = hex_values[remainder];
        num/=16;
    }
	while (i > 0)
    {
        if (capital)
		    count += ft_putchar_fd(ft_toupper(values[--i]), 1);
        else
            count += ft_putchar_fd(values[--i], 1);   
    }
    return count;
}