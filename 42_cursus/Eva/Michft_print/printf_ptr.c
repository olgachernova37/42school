/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhruby <mhruby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:40:53 by mhruby            #+#    #+#             */
/*   Updated: 2024/10/25 13:32:21 by mhruby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_hex_address(unsigned long long n)
{
	int	size;

	size = 0;
	while (n)
	{
		size ++;
		n /= 16;
	}
	return (size);
}

static int	ft_hex_address(unsigned long long n)
{
	char	*base_16;
	int		size;

	size = size_hex_address(n);
	base_16 = "0123456789abcdef";
	if (n < 16)
	{
		if (printf_char(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		ft_hex_address(n / 16);
		ft_hex_address(n % 16);
	}
	return (size);
}

int	printf_ptr(void *ptr)
{
	int	n;

	if (ptr == NULL)
	{
		printf_string("(nil)");
		return (5);
	}
	if (printf_string("0x") == -1)
		return (-1);
	n = ft_hex_address((unsigned long long) ptr);
	if (n != 0)
		return (n + 2);
	else
		return (3);
}
