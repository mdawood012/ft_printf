#include "ft_printf.h"

int handler_string(va_list list, int fd)
{
    return (my_putstr_fd(va_arg(list, char*), fd));
}

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