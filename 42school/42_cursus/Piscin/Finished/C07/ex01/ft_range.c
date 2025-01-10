/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:06:57 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/25 15:23:27 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	lenarr;
	int	*ptr;
	int	i;

	if (min >= max)
	{
		return (NULL);
	}
	lenarr = max - min;
	i = 0;
	ptr = (int *)malloc(lenarr * sizeof(int));
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < lenarr)
	{
		ptr[i] = min + i;
		i++;
	}
	return (ptr);
}
