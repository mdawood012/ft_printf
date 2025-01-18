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

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
    return (1);
}

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
	}
	return (c);
}

int   long_to_hex(long num, int capital)
{
    char *hex_values;
    char values[20];
    int i;
    int count; 
    int remainder;

    hex_values = "0123456789abcdef";
    count = 0;
	i = 0;
	if (num == 0)
        return 0;
    while (num > 0)
    {
        remainder = num % 16;
	    values[i++] = hex_values[remainder];
        num/=16;
    }
	while (i > 0)
    {
        if (capital)
		    count += ft_putchar_fd(ft_toupper(values[--i]), 1);
        else
            count += ft_putchar_fd(values[--i], 1);   
    }
    return count;
}

int	ft_putstr_fd(char *s, int fd)
{
    int count;
	if (!s)
		return (0);
    count = strlen(s);
	write(fd, s, count);
    return (count);
}

int    ft_putptr_fd(char *s, int fd, int capital)
{
    int count;
    long address = (long)s;
    ft_putchar_fd('0', fd);
    ft_putchar_fd('x', fd);
    count = long_to_hex(address, capital) + 2;
    return count;
}

int	ft_putnbr_fd(int n, int fd)
{
    int     count;
	long	num;

    count = 0;
	num = (int) n;
	if (num < 0)
	{
		count += ft_putchar_fd('-', fd);
		num = -1 * num;
	}
	if ((num / 10) > 0)
	{
		count += ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
	else
		ft_putchar_fd(num % 10 + '0', fd);
    count++;
    return count;
}

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

int  ft_nbrthex_fd(int num, int capital)
{
    int count;
    count = long_to_hex(num, capital);
    return count;

}

int	ft_printf(const char *data, ...)
{
	va_list list;
	va_start(list, data);
	int i = 0;
    int count = 0;
    int capital = 90;

	while (data[i] != '\0')
	{
		if (data[i] == '%')
        {
            if (data[i+1]  == 'c')
            {
                count += ft_putchar_fd(va_arg(list, int), 1);
                i++;
            }
            if (data[i+1] == 's')
            {    
                count += ft_putstr_fd(va_arg(list, char *), 1);
                i++;
            }
            if (data[i+1] == 'p')
            {
                count += ft_putptr_fd(va_arg(list, char *), 1, capital > data[i+1]);
                i++;
            }
            if (data[i+1] == 'd' || data[i+1] == 'i')
            {    
                count += ft_putnbr_fd(va_arg(list, int), 1);
                i++;
            }
            if (data[i+1] == 'u')
            {
                ft_putuinbr_fd(va_arg(list, unsigned int), 1);
                i++;
            }
            if (data[i+1] == 'x' || data[i+1] == 'X')
            {
                ft_nbrthex_fd(va_arg(list, int), capital > data[i+1]);
                i++;
            }
            if (data[i+1] == '%')
            {
                ft_putchar_fd('%', 1);
                i++;
            }
        }
        else
        {
            ft_putchar_fd(data[i], 1);
            count++;
        }
		i++;
	}
	va_end(list);
	return (count);
}

// int main(void)
// {
//     int num = 2;
//     int result = ft_printf("%d", num);
//     ft_printf("%d", result);
// }