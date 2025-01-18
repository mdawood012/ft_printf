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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
	}
	return (c);
}

void   long_to_hex(long num, int capital)
{
    char *hex_values;
    char *values;
    int i;
    int remainder;

    hex_values = "0123456789abcdef";
	values = malloc(20);
	i = 0;
	if (!values || num == 0)
        return ;
    while (num > 0)
    {
        remainder = num % 16;
	    values[i++] = hex_values[remainder];
        num/=16;
    }
	while (i > 0)
    {
        if (capital)
		    ft_putchar_fd(ft_toupper(values[--i]), 1);
        else
            ft_putchar_fd(values[--i], 1);
    }
	free(values);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, strlen(s));
}

void    ft_putptr_fd(char *s, int fd, int capital)
{
    long long address = (long long)s;
    ft_putchar_fd('0', fd);
    ft_putchar_fd('x', fd);
    long_to_hex(address, capital);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = (int) n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -1 * num;
	}
	if ((num / 10) > 0)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
	else
		ft_putchar_fd(num % 10 + '0', fd);
}

void ft_putuinbr_fd(unsigned int num, int fd)
{
    if ((num / 10) > 0)
	{
		ft_putuinbr_fd(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
	else
		ft_putchar_fd(num % 10 + '0', fd);
}

void  ft_nbrthex_fd(int num, int capital)
{
    long_to_hex(num, capital);
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
                ft_putchar_fd(va_arg(list, int), 1);
                i++;
            }
            if (data[i+1] == 's')
            {    
                ft_putstr_fd(va_arg(list, char *), 1);
                i++;
            }
            if (data[i+1] == 'p')
            {
                ft_putptr_fd(va_arg(list, char *), 1, capital);
                i++;
            }
            if (data[i+1] == 'd' || data[i+1] == 'i')
            {    
                ft_putnbr_fd(va_arg(list, int), 1);
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
            ft_putchar_fd(data[i], 1);
		i++;
	}
	va_end(list);
	return (count);
}

int main(void)
{
    int a = 0;
    int *ptr =  &a;
    ft_printf("m/y ans: %p\n", ptr);
    int dec = 012;
    ft_printf("in %%i: %i\n", dec);
    dec = 012;
    ft_printf("in dec: %d\n", dec);
    int num = -10;
    ft_printf("in unsigned int: %u\n", (unsigned int)num);
    //printf("Size of long long: %I64d bytes\n", sizeof(long long));
    int n = 56088;
    ft_printf("in hex form: %x\n", n);
    ft_printf("in capitalised hex form: %X", n);
    //ft_printf("%x\n", n);
}
