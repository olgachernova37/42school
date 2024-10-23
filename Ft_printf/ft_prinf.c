/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:20:43 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/23 20:40:30 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		sum_of_printf;

	sum_of_printf = 0;
	va_start(args, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			sum_of_printf += print_specifier(*(++format), args);
		}
		else
			sum_of_printf += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (sum_of_printf);
}
