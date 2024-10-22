/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:19:06 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/19 19:52:24 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\n')
	{
		write(1, &str[len], 1);
		len++;
	}
}

// int main ()
// {
//     char *str="Hello";

//     printf("%s", str);
// }
