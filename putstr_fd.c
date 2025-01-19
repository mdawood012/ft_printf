#include "libftprintf.h"

int	ft_putstr_fd(char *s, int fd)
{
    int count;
	if (!s)
		return (0);
    count = strlen(s);
	write(fd, s, count);
    return (count);
}