/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:21:53 by olcherno          #+#    #+#             */
/*   Updated: 2025/01/23 15:03:59 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	reading(int fd, char **preread, char *buffer);
static int	cutting_line(char **line, char **preread);
static char	*ft_strchr(char *s, int c);

char	*get_next_line(int fd)
{
	static char	*preread;
	char		*buffer;	
	int			status;
	char		*line;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || buffer == NULL)
		return (free(preread), free(buffer), preread = NULL, NULL);
	status = reading(fd, &preread, buffer);
	free(buffer);
	buffer = NULL;
	line = NULL;
	if (status == -1)
		return (NULL);
	if (cutting_line(&line, &preread) == -1)
		return (NULL);
	return (line);
}

static int	reading(int fd, char **preread, char *buffer)
{
	ssize_t	be_read;
	char	*temp;

	be_read = 1;
	while (be_read > 0)
	{
		be_read = read(fd, buffer, BUFFER_SIZE);
		if (be_read == -1)
			return (-1);
		if (be_read == 0)
			break ;
		buffer[be_read] = '\0';
		temp = *preread;
		if (*preread == NULL)
			*preread = ft_strjoin("", buffer);
		else
			*preread = ft_strjoin(*preread, buffer);
		free(temp);
		if (*preread == NULL)
			return (-1);
		if (ft_strchr(*preread, '\n') != NULL)
			break ;
	}
	return (0);
}

static int	cutting_line(char **line, char **preread)
{
	ssize_t	i;
	char	*temp;

	i = 0;
	if (*preread == NULL)
		return (0);
	while ((*preread)[i] != '\n' && (*preread)[i] != '\0')
		i++;
	if ((*preread)[i] == '\n')
		i++;
	*line = ft_substr(*preread, 0, i);
	if (*line == NULL)
		return (free(*preread), *preread = NULL, -1);
	if ((*preread)[i] == '\0')
		temp = NULL;
	else
	{
		temp = ft_strdup(*preread + i);
		if (temp == NULL)
			return (free(*preread), *preread = NULL,
				free(*line), *line = NULL, -1);
		free(*preread);
		*preread = temp;
	}
	return (0);
}

static char	*ft_strchr(char *s, int c)
{
	unsigned int i;
	char cc;

	cc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}
