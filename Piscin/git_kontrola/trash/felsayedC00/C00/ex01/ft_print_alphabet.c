/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:20:41 by felsayed          #+#    #+#             */
/*   Updated: 2024/08/13 17:42:23 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	letters;
	int count;

	count = 0;
	letters = 97;
	while (letters <= 122)
	{
		write(1, &letters, 1);
		count++;
		
	}
}
