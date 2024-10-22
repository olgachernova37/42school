/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:26:53 by emarko            #+#    #+#             */
/*   Updated: 2024/06/28 15:26:54 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_puthex(char *num, unsigned long int n, size_t len)
{
	int	mod;

	mod = 0;
	while (len--)
	{
		if (n >= 16)
		{
			mod = n % 16;
			n /= 16;
		}
		else
			mod = n;
		if (mod >= 10)
			num[len] = mod + 'a' - 10;
		else
			num [len] = mod + '0';
	}
}

size_t	ft_xtoalen(unsigned long int n)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_xtoa(unsigned long int n)
{
	size_t	len;
	char	*num;

	if (n == 0)
		len = 1;
	else
		len = ft_xtoalen(n);
	num = ft_calloc(len + 1, 1);
	if (!num)
		return (NULL);
	ft_puthex(num, n, len);
	return (num);
}
