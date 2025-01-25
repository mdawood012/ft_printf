#include "ft_printf.h"

int	my_putstr_fd(char *s, int fd)
{
    int count;
	count = 0;
    if (s == NULL)
        return (count += my_putstr_fd("(null)", fd));
    count = ft_strlen(s);
	write(fd, s, count);
    return (count);
}