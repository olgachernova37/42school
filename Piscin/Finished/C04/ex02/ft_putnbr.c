/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:04:23 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/20 16:27:15 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	minus_sign;
	char	string;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	minus_sign = '-';
	if (nb < 0)
	{
		write(1, &minus_sign, 1);
		nb = -nb;
	}
	if (nb / 10 != 0)
		ft_putnbr(nb / 10);
	string = (nb % 10) + '0';
	write(1, &string, 1);
}
