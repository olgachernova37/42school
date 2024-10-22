/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:26:32 by emarko            #+#    #+#             */
/*   Updated: 2024/06/28 15:26:33 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_rflags(size_t width, size_t strlen, int flag_zero)
{
	int	count;

	if (width <= strlen)
		return (0);
	count = 0;
	if (flag_zero)
	{
		while (width - strlen > 0)
		{
			count += ft_printc('0');
			width--;
		}
	}
	else
	{
		while (width - strlen > 0)
		{
			count += ft_printc(' ');
			width--;
		}
	}
	return (count);
}

int	ft_print_lflags(size_t width, size_t strlen)
{
	int	count;

	if (width <= strlen)
		return (0);
	count = 0;
	while (width - strlen > 0)
	{
		count += ft_printc(' ');
		width--;
	}
	return (count);
}

int	ft_printsign(int n, t_flag flags)
{
	int	count;

	count = 0;
	if (flags.plus && n >= 0)
		count += ft_printc('+');
	else if (flags.space && n >= 0)
		count += ft_printc(' ');
	else if (n < 0)
		count += ft_printc('-');
	return (count);
}

int	ft_printhash(int hash, int upper)
{
	int	count;

	count = 0;
	if (!hash)
		return (0);
	if (upper)
		count += ft_prints("0X", 2);
	else
		count += ft_prints("0x", 2);
	return (count);
}
