/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maadel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:59:30 by maadel            #+#    #+#             */
/*   Updated: 2024/08/24 15:19:45 by maadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	i;
	int	*ptr;

	size = 0;
	i = 0;
	if (min >= max)
	{
		return (NULL);
	}
	size = max - min;
	ptr = (int *)malloc(size * sizeof(int));
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		ptr[i] = min + i;
		i++;
	}
	return (ptr);
}
