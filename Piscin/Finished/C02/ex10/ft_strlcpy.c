/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:56:35 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/15 15:27:15 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	while (src[count] != '\0')
		++count;
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (count);
}
	int	main(void)
{
	char s1[10] = "FGHg";
	char s2[50] = "abcdef";
	

	printf("%s \n", s1);
	printf("%s \n", s2);
	printf("%d \n", ft_strlcpy(s1, s2, 8));
	printf("%s \n", s1);
}