/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:09:45 by msylaiev          #+#    #+#             */
/*   Updated: 2024/08/10 16:37:02 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	get_char(int n)
{
	char	first;
	char	second;
	char	char_var[2];

	if (n >= 0 && n <= 99)
	{
		first = 48 + (n / 10);
		second = 48 + (n % 10);
		
		char_var[0] = first;
		char_var[1] = second;
		write(1, &char_var, 2);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 99)
	{
		while (b <= 99)
		{
			get_char(a);
			write(1, " ", 1);
			get_char(b);
			if (a != 98)
			{
				write(1, ", ", 2);
			}
			b++;
		}
		a++;
		b = a + 1;
	}
}
