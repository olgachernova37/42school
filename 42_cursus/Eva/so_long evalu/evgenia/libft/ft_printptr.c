/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:26:37 by emarko            #+#    #+#             */
/*   Updated: 2024/06/28 16:31:56 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printp(char *num, t_flag flags, size_t len, int n)
{
	int		count;

	count = 0;
	if (flags.left && (size_t)flags.width > len)
	{
		count += ft_printhash(n, 0);
		count += ft_prints(num, len);
		count += ft_print_lflags((size_t)flags.width, len);
	}
	else if ((size_t)flags.width > len)
	{
		count += ft_print_rflags((size_t)flags.width, len, 0);
		count += ft_printhash(n, 0);
		count += ft_prints(num, len);
	}
	else
	{
		count += ft_printhash(n, 0);
		count += ft_prints(num, len);
	}
	return (count);
}

int	ft_printptr(unsigned long int n, t_flag flags)
{
	size_t	count;
	size_t	len;
	char	*num;

	if (n == 0)
		num = "(nil)";
	else
	{
		num = ft_xtoa(n);
		if (!num)
			return (0);
	}
	len = ft_strlen(num);
	if (flags.width >= 2 && n != 0)
		flags.width -= 2;
	count = ft_printp(num, flags, len, n != 0);
	if (n)
		free(num);
	return (count);
}
