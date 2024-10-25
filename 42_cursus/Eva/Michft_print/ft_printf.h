/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhruby <mhruby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:00:00 by mhruby            #+#    #+#             */
/*   Updated: 2024/10/25 12:20:03 by mhruby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		printf_char(int c);
int		printf_string(char *s);
int		printf_ptr(void *ptr);
int		ft_printf(const char *s, ...);
int		printf_nbr(int n);
int		printf_hex(unsigned int n, int x_switch);
int		printf_uint(unsigned int n);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif