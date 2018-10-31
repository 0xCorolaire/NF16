#include <stdio.h>

int main() {

    int i;
    int *j;
    i = 5;
    j = &i; // j contient l'adresse de la variable i

    printf("\nadresse de i : %x, valeur de i : %d\n", &i, i);
    printf("\nadresse de j : %x, valeur de j : %x, valeur pointée par j : %d\n", &j, j, *j);

    return 0;
}
