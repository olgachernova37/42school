#include <stdio.h>

void ft_print_alphabet(void) {
   
    char letter;

    for (letter = 'a'; letter <= 'z'; letter++) {
        write(1, &letter, 1);
    }

}
