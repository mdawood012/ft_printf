#include "ft_printf.h"
int handler_unsigned(va_list list, int fd)
{
	return (my_putuinbr_fd(va_arg(list, unsigned int), fd));
}
int my_putuinbr_fd(unsigned int num, int fd)
{
    int count;
    count = 0;
    if ((num / 10) > 0)
	{
		count += my_putuinbr_fd(num / 10, fd);
		my_putchar_fd(num % 10 + '0', fd);
	}
	else
	{
		my_putchar_fd(num % 10 + '0', fd);
	}
	count++;
    return count;
}
