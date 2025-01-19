#include "ft_printf.h"

int	my_putnbr_fd(int n, int fd)
{
    int     count;
	long	num;

    count = 0;
	num = (int) n;
	if (num < 0)
	{
		count += my_putchar_fd('-', fd);
		num = -1 * num;
	}
	if ((num / 10) > 0)
	{
		count += my_putnbr_fd(num / 10, fd);
		my_putchar_fd(num % 10 + '0', fd);
	}
	else
		my_putchar_fd(num % 10 + '0', fd);
    count++;
    return count;
}
