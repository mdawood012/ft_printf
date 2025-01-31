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
#include "ft_printf.h"
#include <stdio.h>

int handler_char(va_list list, int fd) 
{
    return (my_putchar_fd(va_arg(list, int), fd));
}

int handler_string(va_list list, int fd)
{
    return (my_putstr_fd(va_arg(list, char*), fd));
}
struct my_specifier my_specifiers[] = {
    {'c', handler_char},
    {'s', handler_string},
};
int ft_printf(const char *data, ...)
{
    va_list list;
    va_start(list, data);
    int i;
    i = 0;
    int j;
    j = 0;
    struct my_specifier my_var;
    while (data[i] != '\0')
    {
        if (data[i] == '%')
        {
            j = 0;
            my_var.specifier = data[i+1];//c
            while (my_specifiers[j].specifier != '\0')
            {
                if (my_specifiers[j].specifier == my_var.specifier)
                {
                    printf("hello");
                    break;
                }
                j++;
            }
        }
        i++;
    }
    va_end(list);
    return (0);
    
}

// int	ft_printf(const char *data,...)
// {
// 	va_list list;
// 	va_start(list, data);
// 	int i = 0;
//     int count = 0;
//     int capital = 88;

// 	while (data[i] != '\0')
// 	{
// 		if (data[i] == '%')
//         {
//             if (data[i+1]  == 'c')
//             {
//                 //handler_char(list, 1);
//                 count += my_putchar_fd(va_arg(list, int), 1);
//                 i++;
//             }
//             else if (data[i+1] == 's')
//             {    
//                 count += my_putstr_fd(va_arg(list, char *), 1);
//                 i++;
//             }
//             else if (data[i+1] == 'p')
//             {
//                 count += my_putptr_fd(va_arg(list, void *), 1, capital = 0);
//                 i++;
//             }
//             else if (data[i+1] == 'd' || data[i+1] == 'i')
//             {    
//                 count += my_putnbr_fd(va_arg(list, int), 1);
//                 i++;
//             }
//             else if (data[i+1] == 'u')
//             {
//                 count += my_putuinbr_fd(va_arg(list, unsigned int), 1);
//                 i++;
//             }
//             else if (data[i+1] == 'x' || data[i+1] == 'X')
//             {
//                 count += long_to_hex(va_arg(list, unsigned int), capital == data[i+1]);
//                 i++;
//             }
//             else if (data[i+1] == '%')
//             {
//                 count += my_putchar_fd('%', 1);
//                 i++;
//             }
//         }
//         else
//             count += my_putchar_fd(data[i], 1);
// 		i++;
// 	}
// 	va_end(list);
// 	return (count);
// }

