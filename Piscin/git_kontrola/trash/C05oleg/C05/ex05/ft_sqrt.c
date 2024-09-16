/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:20:46 by onosul            #+#    #+#             */
/*   Updated: 2024/08/15 15:20:49 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = nb;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (mid * mid == nb)
			return (mid);
		if (mid * mid < nb)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (0);
}
