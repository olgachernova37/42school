/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerasym <agerasym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:05:24 by agerasym          #+#    #+#             */
/*   Updated: 2024/08/10 14:39:16 by agerasym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	o;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			o = j + 1;
			while (o <= '9')
			{
				write(1, &i, 1);
				write(1, &j, 1);
				write(1, &o, 1);
				if (!(i == '7' && j == '8' && o == '9'))
					write(1, ", ", 2);
				o++;
			}
			j++;
		}
		i++;
	}
}

// int	main(void)
// {
// 	ft_print_comb();
// }
