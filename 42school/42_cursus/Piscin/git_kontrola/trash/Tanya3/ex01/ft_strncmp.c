/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanufrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:55:30 by tanufrie          #+#    #+#             */
/*   Updated: 2024/08/18 17:50:16 by tanufrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int	c;

	i = 0;
	c = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			c = s1[i] - s2[i];
			break;
		}
		i++;
	}
	return (c);
}
/*
int	main()
{
	char s1[] = "Coi";
	char s2[] = "Cow";
	int n = 2;
	printf("%d", ft_strncmp(s1, s2, n));
	return (0);
}
*/
