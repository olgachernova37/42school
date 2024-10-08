/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstirber <cstirber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:34:46 by cstirber          #+#    #+#             */
/*   Updated: 2024/10/01 19:09:42 by cstirber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int x)
{
	return ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z') || (x >= '0'
			&& x <= '9'));
}

// int	main(void)
// {
// 	char	z;

// 	z = ' ';

// 	printf ("%d\n", ft_isalnum(z));
// 	return (0);
// }