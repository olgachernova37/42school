// Including the unistd header for the write(2) & read(2) function
#include <unistd.h>
// Including the fcntl header for the open(2) function
#include <fcntl.h>

// Prototypes of the functions declared under the main function
void	ft_putchar_terminal(char c);
void	ft_putchar_test_file(char c);

// main function

/* This function will simply write one character to the terminal on the
 * standard output. As explained above, the fd for stdout is 1, so we put
 * 1 as a first parameter to the write(2) function.
 */
void	ft_putchar_terminal(char c)
{
	write(1, &c, 1);
}

/* This function will open a file called "test.txt" with the open(2) function.
 * Once the file is opened, store the file descriptor in the fd variable.
 * I then check if there was an error opening the file.
 * If no error, I write the character F in the file test.txt
 * If there is an error, I write an error message to the standard error output.
 */
void	ft_putchar_test_file(char c)
{
	int	fd;

	fd = open("test.txt", O_RDWR);
	if (fd > 0)
		write(fd, &c, 1);
	else
		write(2, "test.txt not found.\n", 20);
}

int	main(void)
{
	// calling the ft_putchar_terminal function with character T
	// calling the ft_putchar_test_file function with character F
	ft_putchar_test_file('F');
	return (0);
}
