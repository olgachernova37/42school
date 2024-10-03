/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstirber <cstirber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:20:58 by cstirber          #+#    #+#             */
/*   Updated: 2024/10/01 19:09:46 by cstirber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int x)
{
	if (x >= '0' && x <= '9')
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char    z;

//     z = 'A';
// 	printf ("%d\n", ft_isdigit(z));
// 	return (0);
// }