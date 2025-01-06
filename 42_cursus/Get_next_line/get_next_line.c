/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:21:53 by olcherno          #+#    #+#             */
/*   Updated: 2025/01/06 18:24:57 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char *line;
     char *buffer;
     
     if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
   


     if (!line)
        return (NULL);
}
