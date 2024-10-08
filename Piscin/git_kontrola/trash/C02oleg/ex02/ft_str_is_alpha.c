/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:35:41 by onosul            #+#    #+#             */
/*   Updated: 2024/08/10 18:04:01 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (0);
	}
	while (str[i])
	{
		if (((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
