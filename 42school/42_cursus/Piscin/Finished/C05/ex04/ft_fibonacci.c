/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:33:01 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/23 11:26:50 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	if (index == 0)
	{
		return (0);
	}
	if (index == 1)
	{
		return (1);
	}
	if (index == 2)
	{
		return (1);
	}
	if (index == 3)
	{
		return (2);
	}
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

// int main()
// {
//     printf("%d", ft_fibonacci(10));
// }
