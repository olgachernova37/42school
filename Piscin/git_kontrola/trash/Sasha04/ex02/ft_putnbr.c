/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:50:58 by alisseye          #+#    #+#             */
/*   Updated: 2024/08/19 18:50:29 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char		str[20];
	int			i;
	long int	n;

	i = 0;
	n = nb;
	if (n == 0)
	{
		write(1, "0", 1);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * (-1);
	}
	while (n != 0)
	{
		str[i++] = '0' + (n % 10);
		n /= 10;
	}
	while (i > 0)
	{
		write(1, &str[--i], 1);
	}
}
