/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:26:34 by emarko            #+#    #+#             */
/*   Updated: 2024/06/28 15:26:35 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_upperx(char *num, int upper, size_t len)
{
	size_t	i;

	i = -1;
	if (upper)
	{
		while (++i < len)
			num[i] = ft_toupper(num[i]);
	}
}

static int	ft_printxorder(char *num, t_flag flags, size_t len, int upper)
{
	int		count;
	size_t	total_len;

	if ((size_t)flags.prec_width > len)
		total_len = flags.prec_width;
	else
		total_len = len;
	if (flags.left && (size_t)flags.width > len)
		count = ft_printhash(flags.hash, upper)
			+ ft_printn(num, flags, len)
			+ ft_print_lflags((size_t)flags.width, total_len);
	else if (!flags.zero && (size_t)flags.width > len)
		count = ft_print_rflags((size_t)flags.width, total_len, 0)
			+ ft_printhash(flags.hash, upper)
			+ ft_printn(num, flags, len);
	else
		count = ft_printhash(flags.hash, upper)
			+ ft_printn(num, flags, len);
	return (count);
}

int	ft_printhex(unsigned int n, t_flag flags, int upper)
{
	size_t	count;
	size_t	len;
	char	*num;

	num = ft_xtoa(n);
	if (num == NULL)
		return (0);
	len = ft_strlen(num);
	if (flags.precision)
		flags.zero = 0;
	if (flags.precision && flags.prec_width == 0 && n == 0)
		len = 0;
	if (flags.hash)
	{
		if (n == 0)
			flags.hash = 0;
		else if (flags.width >= 2)
			flags.width -= 2;
	}
	ft_upperx(num, upper, len);
	count = ft_printxorder(num, flags, len, upper);
	free(num);
	return (count);
}
