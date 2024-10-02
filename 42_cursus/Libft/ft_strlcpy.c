/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:38:20 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/02 14:45:34 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t length;
    length = ft_strlen();
    	size_t	i;

	if (!dst || !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
        
	i = 0;
}
