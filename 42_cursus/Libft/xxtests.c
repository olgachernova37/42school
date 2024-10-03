/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xxtests.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:03:46 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/03 17:33:58 by olcherno         ###   ########.fr       */
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
 //    ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
//   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \