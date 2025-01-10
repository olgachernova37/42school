/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:01:46 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/11 12:30:32 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// void	ft_print_alphabet(void)
// {
// 	char	c;

// 	c = 'a';
// 	while (c <= 'z')
// 	{
// 		write(1, &c, 1);
// 		c++;
// 	}
// }

void	ft_print_alphabet(void)
{
	char c;

	c = 'a';
	while (c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
	
}


int	main (void)
{
	ft_print_alphabet();
}
