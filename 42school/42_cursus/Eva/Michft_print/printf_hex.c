/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhruby <mhruby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:30:54 by mhruby            #+#    #+#             */
/*   Updated: 2024/10/25 12:31:43 by mhruby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_hex(unsigned int n)
{
	int	size;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	while (n)
	{
		size++;
		n /= 16;
	}
	return (size);
}

int	printf_hex(unsigned int n, int x_switch)
{
	const char		*base_16;
	const char		*base_16_lower;
	const char		*base_16_upper;	
	int				size;

	size = size_hex(n);
	base_16_lower = "0123456789abcdef";
	base_16_upper = "0123456789ABCDEF";
	if (x_switch == 0)
		base_16 = base_16_upper;
	else
		base_16 = base_16_lower;
	if (n < 16)
	{
		if (printf_char(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		if (printf_hex(n / 16, x_switch) == -1)
			return (-1);
		if (printf_hex(n % 16, x_switch) == -1)
			return (-1);
	}
	return (size);
}
