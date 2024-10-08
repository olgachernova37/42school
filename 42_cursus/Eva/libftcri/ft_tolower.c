/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstirber <cstirber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:02:21 by cstirber          #+#    #+#             */
/*   Updated: 2024/10/01 19:10:17 by cstirber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int x)
{
	if (x >= 'A' && x <= 'Z')
		x += 32;
	return (x);
}

// int main()
// {
// 	char x;

// 	x = 'P';
// 	printf("%c\n", ft_tolower(x));
// 	return (0);
// }
