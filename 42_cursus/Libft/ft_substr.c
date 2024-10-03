/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:32:04 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/03 16:36:52 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    char* substr;
    size_t templ;

    
    size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
    
    
    substr= malloc(len +1);
    if (!substr)
		return (NULL);

    templ = len;
    i = 0;
	while (templ--)
	{
		substr[i] = s[i+len];
		i++;
	}
	substr[i] = '\0';
	return (substr);
    

}
