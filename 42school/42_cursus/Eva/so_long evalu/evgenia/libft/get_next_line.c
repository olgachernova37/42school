/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarko <emarko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:16:40 by emarko            #+#    #+#             */
/*   Updated: 2024/07/24 13:32:18 by emarko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_handle_read_error(char **rest_line)
{
	free(*rest_line);
	*rest_line = NULL;
	return (-1);
}

static char	*ft_read_line(int fd, char *buffer, char **rest_line)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_handle_read_error(rest_line), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!*rest_line)
		{
			*rest_line = ft_calloc(1, 1);
			if (!*rest_line)
				return (NULL);
		}
		temp = *rest_line;
		*rest_line = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (*rest_line);
}

static char	*ft_get_rest_line(char *line)
{
	char	*rest_line;
	size_t	len;

	len = 0;
	while (line[len] != '\0' && line[len] != '\n')
		len++;
	if (line[len] == '\0')
		return (NULL);
	rest_line = ft_substr(line, len + 1, ft_strlen(line) - len);
	if (*rest_line == '\0')
	{
		free(rest_line);
		return (NULL);
	}
	line[len + 1] = '\0';
	return (rest_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest_line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	line = ft_read_line(fd, buffer, &rest_line);
	free(buffer);
	if (!line)
		return (NULL);
	rest_line = ft_get_rest_line(line);
	return (line);
}
