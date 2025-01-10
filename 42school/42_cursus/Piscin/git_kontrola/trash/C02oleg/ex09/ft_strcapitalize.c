/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:06:17 by onosul            #+#    #+#             */
/*   Updated: 2024/08/11 14:27:39 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	func(char *str, int *i, int *new_word)
{
	while (str[*i] != '\0')
	{
		if (str[*i] >= 'A' && str[*i] <= 'Z')
		{
			str[*i] = str[*i] + 32;
		}
		if ((str[*i] >= 'a' && str[*i] <= 'z') || (str[*i] >= '0'
				&& str[*i] <= '9'))
		{
			if ((str[*i] >= 'a' && str[*i] <= 'z') && *new_word)
			{
				str[*i] = str[*i] - 32;
			}
			*new_word = 0;
		}
		else
		{
			*new_word = 1;
		}
		(*i)++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	func(str, &i, &new_word);
	return (str);
}
