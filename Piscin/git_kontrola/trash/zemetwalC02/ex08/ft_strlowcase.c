/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zemetwal <zemetwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:36:50 by zemetwal          #+#    #+#             */
/*   Updated: 2024/08/10 14:00:53 by zemetwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	char	*temp;

	temp = str;
	while (*temp)
	{
		if (*temp >= 'A' && *temp <= 'Z')
		{
			*temp = *temp + 32;
		}
		temp++;
	}
	return (str);
}
