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
                count += my_putchar_fd(va_arg(list, int), 1);
                i++;
            }
            if (data[i+1] == 's')
            {    
                count += my_putstr_fd(va_arg(list, char *), 1);
                i++;
            }
            if (data[i+1] == 'p')
            {
                count += my_putptr_fd(va_arg(list, char *), 1, capital > data[i+1]);
                i++;
            }
            if (data[i+1] == 'd' || data[i+1] == 'i')
            {    
                count += my_putnbr_fd(va_arg(list, int), 1);
                i++;
            }
            if (data[i+1] == 'u')
            {
                my_putuinbr_fd(va_arg(list, unsigned int), 1);
                i++;
            }
            if (data[i+1] == 'x' || data[i+1] == 'X')
            {
                my_nbrthex_fd(va_arg(list, int), capital > data[i+1]);
                i++;
            }
            if (data[i+1] == '%')
            {
                my_putchar_fd('%', 1);
                i++;
            }
        }
        else
        {
            my_putchar_fd(data[i], 1);
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