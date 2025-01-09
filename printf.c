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
	while (data[i] != '\0')
	{
		if (data[i] == '%' && data[i+1] == 'c')
		{
			int result = va_arg(list, int);
			ft_putchar_fd(result, 1); 
			count++;
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
	printf("\n%d", ans);
	//when i run this it is supposed to print a. 
}
