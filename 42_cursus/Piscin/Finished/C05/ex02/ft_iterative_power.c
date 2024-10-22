/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:54:26 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/23 11:26:36 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	base;

	if ((nb == 0 && power != 0) || power < 0)
	{
		return (0);
	}
	if ((power == 0) || ((nb < 0) && (power == 0)))
	{
		return (1);
	}
	base = nb;
	while (power > 1)
	{
		nb = base * nb;
		power--;
	}
	return (nb);
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d", ft_iterative_power(-2, 0));
// 	return (0);
// }
