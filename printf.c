/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdawood <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:58:13 by mdawood           #+#    #+#             */
/*   Updated: 2025/01/08 14:17:59 by mdawood          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
#include <stdio.h>
#include <string.h>

char   *str_print(char const *s, void (*f)(char, int), va_list list)
{
    int i;
    char  *ptr;
    int result;

    if (s == NULL)
        return (NULL);
    ptr = malloc(strlen(s) + 1);
    if (ptr == NULL)
        return (NULL);
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '%' && s[i+1] == 'c')
            f(result = va_arg(list, int), 1);
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, strlen(s));
}

int	ft_printf(const char *data, ...)
{
	va_list list;
	va_start(list, data);
	int i = 0;
    int count = 0;

	while (data[i] != '\0')
	{
		if (data[i] == '%')
        {
            if (data[i+1]  == 'c')
                ft_putchar_fd(va_arg(list, int), 1);
            if (data[i+1] == 's')
                ft_putstr_fd(va_arg(list, char *), 1);

        }
		i++;
	}
	va_end(list);
	return (count);
}
int main(void)
{
	int ans;
	char c = 'a';
	ans = ft_printf("%c", c);
    //printf("\n%d", ans);
    char *s = "hello";
    ans = ft_printf("%s", s);
    printf("Size of long: %zu bytes\n", sizeof(long));
	//printf("\n%d", ans);
	//when i run this it is supposed to print a. 
}
