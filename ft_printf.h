/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdawood <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:42:04 by mdawood           #+#    #+#             */
/*   Updated: 2025/01/24 12:37:07 by mdawood          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>s
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
struct my_specifier
{
    char specifier;
    int (*handler)(va_list list, int capital);
};
extern struct my_specifier my_specifiers[];
int	ft_printf(const char *data, ...);
int	my_putchar_fd(char c, int fd);
int	my_putstr_fd(char *s, int fd);
int 	my_putptr_fd(void *s, int fd, int capital);
int	my_putnbr_fd(int n, int fd);
int 	long_to_hex(unsigned long num, int capital);
int 	my_putuinbr_fd(unsigned int num, int fd);
#endif
