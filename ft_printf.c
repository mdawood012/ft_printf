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

int handle_specifier(char specifier, va_list list, int fd)
{
    int i;
    i = 0;

    while (my_specifiers[i].specifier != '\0')
    {
        if (my_specifiers[i].specifier == specifier)
        {
            return (my_specifiers[i].handler(list, fd));
        }
        i++;
    }
    return (0);
}
struct my_specifier my_specifiers[] = {
    {'c', handler_char},
    {'s', handler_string},
    {'p', handler_pointer},
    {'d', handler_decimal},
    {'i', handler_decimal},
    {'u', handler_unsigned},
    {'x', handler_hex},
    {'X', handler_hex_upper},
};

int ft_printf(const char *data, ...)
{
    va_list list;
    va_start(list, data);
    int count;
    int i;

    count = 0;
    i = 0;
    while (data[i] != '\0')
    {
        if (data[i] == '%')
        {
            count += handle_specifier(data[i+1], list, 1);
            if (data[i+1] == '%')
                count += my_putchar_fd('%', 1);
            i++;

        }
        else
            count += write(1, &data[i], 1);
        i++;
    }
    va_end(list);
    return (count);
}

