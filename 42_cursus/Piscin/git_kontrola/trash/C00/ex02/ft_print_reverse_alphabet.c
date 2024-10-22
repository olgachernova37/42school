/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerasym <agerasym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:24:46 by agerasym          #+#    #+#             */
/*   Updated: 2024/08/10 11:32:34 by agerasym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	t;

	t = 'z';
	while (t >= 'a')
	{
		write (1, &t, 1);
		t--;
	}
}
//int main(void)
//{
//ft_print_reverse_alphabet();
//}
