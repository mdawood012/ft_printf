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
void   long_to_hex(long num)
{
    char hex_values[] = "0123456789abcdef";
	char *values = malloc(20);
	int i = 0;
	if (!values)
        return;
    if (num == 0)
    {
        values[i++] = '0';
        return ;
    }
    while (num > 0)
    {
        int remainder = num % 16;
	    values[i++] = hex_values[remainder];
        num/=16;
    }
	while (i > 0)
		ft_putchar_fd(values[--i], 1);
	free(values);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, strlen(s));
}
void    ft_putptr_fd(char *s, int fd)
{
    long address = (long)s;
    ft_putchar_fd('0', fd);
    ft_putchar_fd('x', fd);
    long_to_hex(address);
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
void  ft_nbrthex_fd(int num)
{
    long_to_hex(num);
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
                ft_putptr_fd(va_arg(list, char *), 1);
                i++;
            }
            if (data[i+1] == 'd')
            {    
                ft_putnbr_fd(va_arg(list, int), 1);
                i++;
            }
            if (data[i+1] == 'i')
            {
                ft_putnbr_fd(va_arg(list, int), 1);
                i++;
            }
            if (data[i+1] == 'u')
            {
                ft_putuinbr_fd(va_arg(list, unsigned int), 1);
                i++;
            }
            if (data[i+1] == 'x')
            {
                ft_nbrthex_fd(va_arg(list, int));;
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
    char a = 'a';
    char *ptr =  &a;
    ft_printf("m/y ans: %p\n", ptr);
    int dec = 012;
    ft_printf("in %%i: %i\n", dec);
    dec = 012;
    ft_printf("in dec: %d\n", dec);
    int num = -10;
    ft_printf("%u\n", (unsigned int)num);
    int n = 56088;
    printf("%x", n);
    ft_printf("%x\n", n);
}
