#include <stdio.h>

int main() {

    int nb;
    printf("Veuillez saisir un nombre...\n");
    scanf("%d", &nb);

    if(nb != 0) // accolades facultatives quand instructions sur une seule ligne
        printf("Le nombre %d est OK\n", nb);
    else
        printf("Le nombre %d est KO\n", nb);
    

    return 0;
}
