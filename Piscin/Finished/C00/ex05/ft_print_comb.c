/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:31:26 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/11 12:24:10 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numb(char a, char b, char c)
{
	if (a == '7')
	{
		write(1, "789", 3);
	}
	else
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	first;
	char	second;
	char	third;

	first = '0';
	second = '0';
	third = '0';
	while (first <= '7')
	{
		while (second <= '8')
		{
			second++;
			third = second + 1;
			while (third <= '9')
			{
				ft_print_numb(first, second, third);
				third++;
			}
		}
		first++;
		second = first;
		third = second;
	}
}
