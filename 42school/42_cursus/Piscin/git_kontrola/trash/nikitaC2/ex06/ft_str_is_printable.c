/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:03:29 by mdehtiar          #+#    #+#             */
/*   Updated: 2024/08/19 15:13:00 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] >= 126)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
int main()
{
	// char	d[]="asdfasdasdd";
	// char	s[]="bnmcz";
	printf("%d", ft_str_is_printable("!!!!"));
}