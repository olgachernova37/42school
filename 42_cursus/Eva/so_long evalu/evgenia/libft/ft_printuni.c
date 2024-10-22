/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:26:44 by emarko            #+#    #+#             */
/*   Updated: 2024/06/28 15:26:45 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printuorder(char *num, t_flag flags, size_t len)
{
	int		count;
	size_t	total_len;

	if ((size_t)flags.prec_width > len)
		total_len = flags.prec_width;
	else
		total_len = len;
	count = 0;
	if (flags.left && (size_t)flags.width > len)
	{
		count += ft_printn(num, flags, len);
		count += ft_print_lflags((size_t)flags.width, total_len);
	}
	else if (!flags.zero && (size_t)flags.width > len)
	{
		count += ft_print_rflags((size_t)flags.width, total_len, 0);
		count += ft_printn(num, flags, len);
	}
	else
		count += ft_printn(num, flags, len);
	return (count);
}

int	ft_printuni(unsigned int n, t_flag flags)
{
	size_t	count;
	size_t	len;
	char	*num;

	num = ft_utoa(n);
	if (num == NULL)
		return (0);
	len = ft_strlen(num);
	if (flags.precision)
		flags.zero = 0;
	if (flags.precision && flags.prec_width == 0 && n == 0)
		len = 0;
	count = ft_printuorder(num, flags, len);
	free(num);
	return (count);
}
