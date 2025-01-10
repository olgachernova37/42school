/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:26:22 by emarko            #+#    #+#             */
/*   Updated: 2024/06/28 15:26:23 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printn(char *num, t_flag flags, size_t len)
{
	int		count;

	count = 0;
	if (flags.precision)
		count += ft_print_rflags((size_t)flags.prec_width, len, 1);
	else if (flags.zero)
		count += ft_print_rflags((size_t)flags.width, len, 1);
	count += ft_prints(num, len);
	return (count);
}

static int	ft_printorder(char *num, int n, t_flag flags, size_t len)
{
	int		count;
	size_t	total_len;

	if ((size_t)flags.prec_width > len)
		total_len = flags.prec_width;
	else
		total_len = len;
	if (flags.left && (size_t)flags.width > total_len)
	{
		count = ft_printsign(n, flags);
		count += ft_printn(num, flags, len);
		count += ft_print_lflags((size_t)flags.width, total_len);
	}
	else if (!flags.zero && (size_t)flags.width > total_len)
	{
		count = ft_print_rflags((size_t)flags.width, total_len, 0);
		count += ft_printsign(n, flags);
		count += ft_printn(num, flags, len);
	}
	else
	{
		count = ft_printsign(n, flags);
		count += ft_printn(num, flags, len);
	}
	return (count);
}

int	ft_printdec(int n, t_flag flags)
{
	size_t	count;
	size_t	len;
	char	*num;

	num = ft_itoa(n);
	if (num == NULL)
		return (0);
	if (n < 0)
		num++;
	len = ft_strlen(num);
	if (flags.precision)
		flags.zero = 0;
	if (flags.precision && flags.prec_width == 0 && n == 0)
		len = 0;
	if (flags.width > 0 && (((flags.plus || flags.space) && n >= 0)
			|| n < 0))
		flags.width--;
	count = ft_printorder(num, n, flags, len);
	if (n < 0)
		num--;
	free(num);
	return (count);
}
