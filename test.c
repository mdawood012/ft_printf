#include "libftprintf.h"
#include <stdio.h>
#include <string.h>

char   *str_print(char const *s, char (*f)(int, char), va_list list)
{
    int i;
    char   *ptr;

    if (s == NULL)
        return (NULL);
    ptr = malloc(strlen(s) + 1);
    if (ptr == NULL)
        return (NULL);
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '%' && s[i+1] == 'c')
        {
            int result = va_arg(list, int);
            ptr[i] = f(result, result);
        }
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


int	ft_printf(const char *data, ...)
{
	va_list list;
	va_start(list, data);
	int i = 0;
	int count = 0;


    char *result = str_print(data, ft_putchar_fd, list);
    printf("%s", result);
	// while (data[i] != '\0')
	// {
	// 	ft_strmapi(data, ft_putchar_fd);
	// 	// if (data[i] == '%' && data[i+1] == 'c')
	// 	// {
	// 	// 	int result = va_arg(list, int);
	// 	// 	ft_putchar_fd(result, 1); 
	// 	// 	count++;
	// 	// }
	// 	//i++;
	// }
	va_end(list);
	return (count);
}
