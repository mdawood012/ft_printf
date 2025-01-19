/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdawood <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:05:46 by mdawood           #+#    #+#             */
/*   Updated: 2025/01/09 12:40:24 by mdawood          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
int	ft_printf(const char *data, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int ft_putptr_fd(char *s, int fd, int capital);
int	ft_putnbr_fd(int n, int fd);
int long_to_hex(long num, int capital);
int ft_putuinbr_fd(unsigned int num, int fd);
int ft_nbrthex_fd(int num, int capital);
#endif
