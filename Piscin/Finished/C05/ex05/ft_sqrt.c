/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:24:14 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/23 11:26:55 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	result;

	result = 0;
	if (nb == 1)
	{
		return (1);
	}
	while (result < nb)
	{
		if (result * result == nb)
			return (result);
		else
			result++;
	}
	return (0);
}

// int	i;
// int	sq;
// i = 1;
// sq = 1;
// if (nb == 0)
// 	return (0);
// while (i * i < nb)
// {
// 	i++;
// }
// if ((nb % i) == 0)
// 	return (i);
// else
// 	return (0);