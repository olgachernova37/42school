/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:46:44 by arudenko          #+#    #+#             */
/*   Updated: 2024/10/02 15:27:15 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*next_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!buffer || buffer[0] == '\0')
		return (free(buffer), NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!line)
		return (free(buffer), NULL);
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*write_the_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*join_and_free_resultstr(char *buffer, char *resultstr)
{
	char	*temporary;

	if (!resultstr)
		return (NULL);
	temporary = ft_strjoin(buffer, resultstr);
	if (buffer)
		free(buffer);
	return (temporary);
}

char	*read_the_line(int fd, char *buffer)
{
	int		res;
	char	*resultstr;

	resultstr = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!resultstr)
		return (NULL);
	res = 1;
	while (res > 0)
	{
		res = read(fd, resultstr, BUFFER_SIZE);
		if (res == -1)
		{
			free(resultstr);
			free(buffer);
			return (NULL);
		}
		resultstr[res] = '\0';
		buffer = join_and_free_resultstr(buffer, resultstr);
		if (!buffer)
			return (free(resultstr), NULL);
		if (ft_strchr(buffer, '\n') || (res == 0))
			break ;
	}
	free(resultstr);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_MAX];
	char		*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1, sizeof(char));
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = read_the_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = write_the_line(buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = next_line(buffer[fd]);
	return (line);
}

// // Modify this function to include debug statements
// char    *read_the_line(int fd, char *buffer)
// {
// 	int     res;
// 	char    *resultstr;

// 	resultstr = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	if (!resultstr)
// 		return (NULL);
// 	res = 1;
// 	while (res > 0)
// 	{
// 		res = read(fd, resultstr, BUFFER_SIZE);
// 		if (res == -1)
// 		{
// 			free(resultstr);
// 			free(buffer);
// 			return (NULL);
// 		}
// 		resultstr[res] = '\0';
// 		printf("Read %d bytes: \"%s\"\n", res, resultstr); // Debug statement
// 		buffer = join_and_free_resultstr(buffer, resultstr);
// 		if (!buffer)
// 			return (free(resultstr), NULL);
// 		printf("Current buffer content: \"%s\"\n", buffer); // Debug statement
// 		if (ft_strchr(buffer, '\n') || (res == 0))
// 			break ;
// 	}
// 	free(resultstr);
// 	return (buffer);
// }
//************************************************/
// // Main function to test get_next_line
// int main(void)
// {
// 	int     fd;
// 	char    *line;
// 	int     line_number = 1;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Line %d: \"%s\"\n", line_number, line);
// 		free(line);
// 		line_number++;
// 	}
// 	close(fd);
// 	return (0);
// }
//***********************************************/
// #include <fcntl.h>
// #include <stdio.h>
// #include "get_next_line_bonus.h"

// int main(void)
// {
// 	int		fd1, fd2;
// 	char	*line1, *line2;
// 	int		i;

// 	fd1 = open("file1.txt", O_RDONLY);
// 	fd2 = open("file2.txt", O_RDONLY);
// 	if (fd1 == -1 || fd2 == -1)
// 		return (1);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		line1 = get_next_line(fd1);
// 		line2 = get_next_line(fd2);
// 		printf("Line from fd1: %s", line1);
// 		printf("Line from fd2: %s", line2);
// 		free(line1);
// 		free(line2);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
