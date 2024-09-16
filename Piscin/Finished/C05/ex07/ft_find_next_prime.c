/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:42:00 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/23 11:27:04 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
	{
		return (0);
	}
	while (i < (nb / 2) + 1)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;
	int	ok;

	i = 0;
	ok = 0;
	while (ok == 0)
	{
		ok = check_prime(nb + i);
		i++;
	}
	return (nb + i - 1);
}
// #include <stdio.h>
// int main()
// {
//     printf("%d", ft_find_next_prime(123));

// 	return(0);
// }