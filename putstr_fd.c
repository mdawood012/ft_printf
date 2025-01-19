#include "ft_printf.h"

int	my_putstr_fd(char *s, int fd)
{
    int count;
	if (!s)
		return (0);
    count = ft_strlen(s);
	write(fd, s, count);
    return (count);
}