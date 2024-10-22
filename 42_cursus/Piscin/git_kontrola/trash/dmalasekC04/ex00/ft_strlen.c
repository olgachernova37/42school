/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:06:42 by dmalasek          #+#    #+#             */
/*   Updated: 2024/08/14 13:46:15 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char string[] = "42prague";
// 	int result = ft_strlen(string);
// 	printf("Result: %d", result);
// }