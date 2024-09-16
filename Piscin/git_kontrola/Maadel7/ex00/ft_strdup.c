/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maadel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:26:36 by maadel            #+#    #+#             */
/*   Updated: 2024/08/24 15:20:36 by maadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (j <= i)
	{
		ptr[j] = src[j];
		j++;
	}
	return (ptr);
}
