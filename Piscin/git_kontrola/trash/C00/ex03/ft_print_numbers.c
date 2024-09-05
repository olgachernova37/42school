/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerasym <agerasym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:33:14 by agerasym          #+#    #+#             */
/*   Updated: 2024/08/10 11:55:17 by agerasym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	y;

	y = '0';
	while (y <= '9')
	{
		write(1, &y, 1);
		y++;
	}
}
//int main()
//{
//ft_print_numbers();
//}
