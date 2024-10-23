#include "ft_printf.h"

int main()
{
    int counters = 0;
    ft_printf("Pointer :%p\n", &counters);
       printf("Pointer :%p\n", &counters);

    ft_printf("STR :%s, %s\n", "Hello", "World");
       printf("STR :%s, %s\n", "Hello", "World");
       



       int result = 0;

	result = ft_printf("%p\n", (void *)&result);
	printf("%p", (void *)&result);
	printf("%i",052);

	ft_printf("%i\n",0x2A);
	ft_printf("%d\n",0x2A);
	printf("%u\n", -100);
	ft_printf("%u\n", 100);
	ft_printf("%x\n",10);
	ft_printf("The discount is 20%% off!\n");
	// ft_printf("%x", 100);

    // ft_printf("%s", "");
	// ft_printf("this is a %s", "test");
	ft_printf("%s", "-24");

	ft_printf("%s", "0x0000042");
	ft_printf("some naugty tests: %s", "0000%");
	ft_printf("some naugty tests: %s", "    %");
	ft_printf("some naugty tests: %s", "%000");
	// ft_printf("%s", null_str);
	// ft_printf("%s everywhere", null_str);
	// ft_printf("everywhere %s", null_str);
	ft_printf("%s", "h");
	ft_printf("t%st%s", "a", "u");
	ft_printf("%s%s%s%s%s%s", "a", "i", "u", "e", "o", "l"); 
}