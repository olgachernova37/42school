#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


	void	*__wrap_malloc(size_t size)
		{
			void	*ptr;
			static int i = 0;
			if (i != 1)
				ptr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
			else
				ptr = NULL;
			dprintf(2, "%i malloc(%zu) = %p\n", i, size, ptr);
			i++;
			return (ptr);
		}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}
	line = get_next_line(fd);
    printf("%s", line);
	__wrap_malloc(1);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
