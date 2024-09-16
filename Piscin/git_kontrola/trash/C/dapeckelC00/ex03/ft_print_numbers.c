#include <stdio.h>

void ft_print_numbers(void) {
   
    char digit;

    for (digit = '0'; digit <= '9'; digit++) {
        write(1, &digit, 1);
    }
}

