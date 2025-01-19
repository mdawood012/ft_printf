#include "libftprintf.h"

int ft_putuinbr_fd(unsigned int num, int fd)
{
    int count;
    count = 0;
    if ((num / 10) > 0)
	{
		ft_putuinbr_fd(num / 10, fd);
		count += ft_putchar_fd(num % 10 + '0', fd);
	}
	else
		count += ft_putchar_fd(num % 10 + '0', fd);
    return count;
}