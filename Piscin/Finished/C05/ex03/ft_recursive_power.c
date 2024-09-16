/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:33:08 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/23 11:26:41 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
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
	if (power == 1)
	{
		return (nb);
	}
	base = nb;
	if (power > 1)
	{
		nb = ft_recursive_power(base, (power - 1));
	}
	nb *= base;
	return (nb);
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d", ft_recursive_power(2, 3));
// 	return (0);
// }
