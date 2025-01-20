#include "ft_printf.h"

int	my_putstr_fd(char *s, int fd)
{
    int count;
    char *temp = "(null)";
	count = 0;
    if (s == NULL)
    {
        count += 6;
        write(1, temp, 6);
        return (count);
    }
    count = ft_strlen(s);
	write(fd, s, count);
    return (count);
}

//ive got to count every single character and so in this case it should be 18. 