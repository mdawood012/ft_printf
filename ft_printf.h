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
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"
int	ft_printf(const char *data, ...);
int	my_putchar_fd(char c, int fd);
int	my_putstr_fd(char *s, int fd);
int 	my_putptr_fd(char *s, int fd, int capital);
int	my_putnbr_fd(int n, int fd);
int 	long_to_hex(long num, int capital);
int 	my_putuinbr_fd(unsigned int num, int fd);
int 	my_nbrthex_fd(int num, int capital);
#endif
