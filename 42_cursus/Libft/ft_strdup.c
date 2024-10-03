/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:43:51 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/03 17:55:11 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
    char * new;
    int i;

    i = 0;
    if(!(new = (char *)malloc(sizeof(char) * ft_strlen(s) +1)))
    {
        return NULL;
    }
    while (*s)
    {
        new[i++] = *s++;
    }
    new[i] = '\0';
    return(new);
}
