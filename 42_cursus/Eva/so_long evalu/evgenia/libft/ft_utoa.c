/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:26:51 by emarko            #+#    #+#             */
/*   Updated: 2024/06/28 15:26:52 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned int n)
{
	int		size;
	long	i;

	size = 0;
	i = 1;
	if (n == 0)
		return (1);
	while (n / i != 0)
	{
		i *= 10;
		size++;
	}
	return (size);
}

static void	ft_putu(unsigned int n, char *num, size_t len)
{
	int	mod;

	mod = 0;
	while (len--)
	{
		if (n >= 10)
		{
			mod = n % 10;
			n /= 10;
		}
		else
			mod = n;
		num [len] = mod + '0';
	}
}

char	*ft_utoa(unsigned int n)
{
	char	*num;
	size_t	len;

	len = ft_len(n);
	num = ft_calloc(len + 1, 1);
	if (!num)
		return (NULL);
	ft_putu(n, num, len);
	return (num);
}
