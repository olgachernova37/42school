/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:06:34 by dgordenk          #+#    #+#             */
/*   Updated: 2025/01/07 17:09:37 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stor = NULL;
	char		*line;
	int			rd;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	rd = read_and_store(fd, &stor);
	if (rd < 0 || !stor || (*stor == '\0' && rd == 0))
		return (free(stor), stor = NULL, NULL);
	line = trim_the_line(&stor);
	return (line);
}

int	read_and_store(int fd, char **stor)
{
	int		rd;
	char	*new;

	rd = 1;
	new = malloc(BUFFER_SIZE + 1);
	if (!new)
		return (-1);
	while (rd > 0)
	{
		rd = read(fd, new, BUFFER_SIZE);
		if (rd < 0)
		{
			free(new);
			return ( -1);
			}
		new[rd] = '\0';
		*stor = free_storeg(*stor, new);
		if (!*stor)
			return (free(new), -1);
		if (ft_strchr(*stor, '\n'))
			break ;
	}
	free(new);
	return (rd);
}

char	*free_storeg(char *stor, const char *s2)
{
	char	*res;
	int		len;
	int		lenn;

	len = ft_strlen(stor);
	lenn = ft_strlen(s2);
	res = malloc(len + lenn + 1);
	if (!res)
		return (free(stor), stor = NULL, NULL);
	ft_memcpy(res, stor, len);
	ft_memcpy(res + len, s2, lenn);
	res[len + lenn] = '\0';
	free(stor);
	return (res);
}

char	*trim_the_line(char **stor)
{
	char	*line;
	char	*left;
	int		i;

	i = 0;
	while ((*stor)[i] && (*stor)[i] != '\n')
		i++;
	if ((*stor)[i] == '\n')
		i++;
	line = allocates_copy(*stor, i);
	left = allocates_copy(*stor + i, ft_strlen(*stor + i));
	free(*stor);
	if (!line || !left)
		return (free(line), free(left), *stor = NULL, NULL);
	*stor = left;
	return (line);
}

char	*allocates_copy(const char *src, int len)
{
	char	*dest;

	if (len == 0)
	{
		dest = malloc(1);
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, src, len);
	dest[len] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	int fd = open("/nfs/homes/dgordenk/get_next_line/file.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s\n", (line));
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }
