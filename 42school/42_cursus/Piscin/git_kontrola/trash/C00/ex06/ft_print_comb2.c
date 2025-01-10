/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerasym <agerasym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:14:27 by agerasym          #+#    #+#             */
/*   Updated: 2024/08/10 12:35:38 by agerasym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		t;
	int		u;
	char	digits[4];

	t = 0;
	while (t <= 98)
	{
		u = t + 1;
		while (u <= 99)
		{
			digits[0] = (t / 10) + '0';
			digits[1] = (t % 10) + '0';
			digits[2] = (u / 10) + '0';
			digits[3] = (u % 10) + '0';
			write(1, digits, 2);
			write(1, " ", 1);
			write(1, digits + 2, 2);
			if (t != 98 || u != 99)
				write(1, ", ", 2);
			u++;
		}
		t++;
	}
}

// int	main(void)
// {
// 	ft_print_comb2();
// }
