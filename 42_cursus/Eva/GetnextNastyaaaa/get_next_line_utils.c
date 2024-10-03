/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:36:24 by arudenko          #+#    #+#             */
/*   Updated: 2024/09/30 14:56:37 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc((len1 + len2 + 1) * sizeof(char));
	if (!result)
		return (NULL);
	joining(s1, s2, result);
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*joining(char const *s1, char const *s2, char *result)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[j])
		{
			result[i + j] = s2[j];
			j++;
		}
	}
	result[i + j] = '\0';
	return (result);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;
	size_t	total_size;
	size_t	i;

	i = 0;
	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	total_size = nitems * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	if (ptr == NULL)
		return (NULL);
	while (i < total_size)
	{
		*((char *)ptr + i) = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}
