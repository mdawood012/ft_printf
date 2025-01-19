#include "libftprintf.h"

int my_putuinbr_fd(unsigned int num, int fd)
{
    int count;
    count = 0;
    if ((num / 10) > 0)
	{
		my_putuinbr_fd(num / 10, fd);
		count += my_putchar_fd(num % 10 + '0', fd);
	}
	else
		count += my_putchar_fd(num % 10 + '0', fd);
    return count;
}