/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xxtests.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:03:46 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/03 15:32:34 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>


int	ft_isdigit(int c);

int	main(void)
{
	char	c;

	c = '5';
	printf("Result when numeric character is passed: %d", ft_isdigit(c));
	c = '+';
	printf("\nResult when non-numeric character is passed: %d", ft_isdigit(c));
	return (0);
}
