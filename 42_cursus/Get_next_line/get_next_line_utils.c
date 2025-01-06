/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:21:42 by olcherno          #+#    #+#             */
/*   Updated: 2025/01/06 16:55:43 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c) // look for and return pointer on C character

{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strdup(const char *s) //dublicated with alloc memory
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len) // TAKE len characters from *s from Start(position in *s)
{
	char	*resstr;
	size_t	i;
	size_t	j;
	size_t	s_len;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	s_len = strlen(s);
	if (start >= s_len)
		return (strdup(""));
	if (start + len < start)
		len = s_len - start;
	else if (start + len > s_len)
		len = s_len - start;
	resstr = (char *)malloc(sizeof(char) * (len + 1));
	if (resstr == NULL)
		return (NULL);
	while (j < len && s[start + j])
		resstr[j++] = s[start + i++];
	resstr[j] = '\0';
	return (resstr);
}

char	*ft_strjoin(char const *s1, char const *s2) //CONCATINATE S1 AND S2 (s1S2)
{
    char	*new;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

    lens1 = ft_strlen(s1);
    lens2 = ft_strlen(s2);

    new = (char *) malloc(sizeof(char) * (lens1 + lens2 + 1));
    if (!new)
		return (NULL);
    i = 0;
    while (i < lens1)
    {
        new[i]=s1[i];
        i++;
    }
    while (i < lens1 + lens2)
    {
        new[i]=s1[i-lens1];
        i++;
    }
    new[i] = '\0';
	return (new);
}
