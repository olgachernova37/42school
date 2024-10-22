#include <stdio.h>

void ft_print_reverse_alphabet(void) {
   
    char letter;

    for (letter = 'z'; letter <= 'a'; letter--) {
        write(1, &letter, 1);
    }

}
