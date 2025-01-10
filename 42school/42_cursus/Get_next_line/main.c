/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:21:08 by okraus            #+#    #+#             */
/*   Updated: 2025/01/07 16:37:19 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

//cc main.c get_next_line.c get_next_line_utils.c -g -Wl,-wrap,malloc -Wl,-wrap,free

/* 
 * Link-time interposition of malloc and free using the static
 * linker's (ld) "--wrap symbol" flag.
 * 
 * Compile the executable using "-Wl,--wrap,malloc -Wl,--wrap,free".
 * This tells the linker to resolve references to malloc as
 * __wrap_malloc, free as __wrap_free, __real_malloc as malloc, and
 * __real_free as free.
 */

void	*__real_malloc(size_t size);
void	__real_free(void *ptr);

/* 
 * __wrap_malloc - malloc wrapper function 
 */
void	*__wrap_malloc(size_t size)
{
	void	*ptr;
    static int i = 0;
	if (i != 1)
		ptr = __real_malloc(size);
	else
		ptr = NULL;
	dprintf(2, "%i malloc(%zu) = %p\n", i, size, ptr);
    i++;
	return (ptr);
}

/* 
 * __wrap_free - free wrapper function 
 */
void	__wrap_free(void *ptr)
{
	dprintf(2, "free(%p)\n", ptr);
	__real_free(ptr);
}

char	*get_next_line(int fd);

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	srand(time(NULL));
	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("fd: %d | %s", fd, line);
		free(line);
		line = get_next_line(fd);
	}
	printf("fd: %d | %s\n", fd, line);
	free(line);
	if (fd > 0)
		close(fd);
	return (0);
}
