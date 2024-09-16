/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:27:11 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/19 19:22:16 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[i] != '\0' && i < nb)
	{
		dest[len] = src[i];
		i++;
		++len;
	}
	dest[len] = '\0';
	return (dest);
}
// 	int	main(void)
// {
// 	char s1[10] = "FGHg";
// 	char *s2 = "1234";

// 	printf("%s \n", s1);
// 	printf("%s \n", s2);
// 	printf("%s \n", ft_strncat(s1, s2, 3));
// }
