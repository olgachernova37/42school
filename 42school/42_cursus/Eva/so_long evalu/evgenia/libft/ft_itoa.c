/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:05:06 by emarko            #+#    #+#             */
/*   Updated: 2024/06/06 19:05:07 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int		size;
	long	i;

	size = 0;
	i = 1;
	while (n / i != 0)
	{
		i *= 10;
		size++;
	}
	return (size);
}

static void	ft_put_num(char *str, long n, int size, int i)
{
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n >= 10)
	{
		ft_put_num(str, n / 10, size, i + 1);
		ft_put_num(str, n % 10, size, i);
	}
	else
		str[size - i - 1] = n + '0';
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	if (n == 0)
		size = 1;
	else
		size = ft_size(n);
	if (n < 0)
		size++;
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	ft_put_num(str, n, size, 0);
	str[size] = '\0';
	return (str);
}
