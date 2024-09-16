/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zemetwal <zemetwal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:18:00 by zemetwal          #+#    #+#             */
/*   Updated: 2024/08/10 13:35:50 by zemetwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	char	*temp;

	temp = str;
	while (*temp)
	{
		if (*temp >= 'a' && *temp <= 'z')
		{
			*temp = *temp - 32;
		}
		temp++;
	}
	return (str);
}
