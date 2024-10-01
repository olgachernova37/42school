
// #include <ctype.h>
#include <stdio.h>

int	ft_isdigit(int c);

int main()
{
    char c;
    c='5';
    printf("Result when numeric character is passed: %d", ft_isdigit(c));

    c='+';
    printf("\nResult when non-numeric character is passed: %d", ft_isdigit(c));

	return (0);
}
