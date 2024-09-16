/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:40:20 by olcherno          #+#    #+#             */
/*   Updated: 2024/08/25 15:56:23 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		lensrc;
	int		lenptr;
	char	*ptr;

	lensrc = 0;
	lenptr = 0;
	while (src[lensrc] != '\0')
	{
		lensrc++;
	}
	ptr = (char *)malloc((lensrc + 1) * sizeof(char));
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (lenptr <= lensrc)
	{
		ptr[lenptr] = src[lenptr];
		lenptr++;
	}
	return (ptr);
}
// #include<stdio.h>
// #include<string.h>

// int main()
// {
//     char source[] = "GeeksForGeeks";

//     // A copy of source is created dynamically
//     // and pointer to copy is returned.
//     char* target = strdup(source);

//     printf("%s", target);
//     return (0);
// }
