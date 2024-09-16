/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:16:24 by dmalasek          #+#    #+#             */
/*   Updated: 2024/08/14 14:08:47 by dmalasek         ###   ########.fr       */
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
// #include <stdio.h>
// int	main(void)
// {
// 	int	integer;

// 	integer = 42;
// 	ft_putnbr(integer);
// }