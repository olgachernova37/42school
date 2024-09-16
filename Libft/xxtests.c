
// #include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	int	result;

	result = 0;
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		result = c;
	}
	return (result);
}

int	main(void)
{
	char c;
	c = 'Q';
	printf("\nResult when uppercase alphabet is passed: %d", ft_isalpha(c));

	c = 'q';
	printf("\nResult when lowercase alphabet is passed: %d", ft_isalpha(c));

	c = '+';
	printf("\nResult when non-alphabetic character is passed: %d", isalpha(c));

	return (0);
}