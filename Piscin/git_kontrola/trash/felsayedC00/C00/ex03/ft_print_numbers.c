/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:09:58 by felsayed          #+#    #+#             */
/*   Updated: 2024/08/13 17:48:44 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	digit;

	digit = 48;
	while (digit <= 57)
	{
		write(1, &digit, 1);
		digit++;
	}
}

int	main (void)
{
	ft_print_numbers();
}