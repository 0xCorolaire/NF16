#include <stdio.h>

int main() {

    int nb;
    printf("Veuillez saisir un nombre...\n");
    scanf("%d", &nb);

    if(nb>=0 && nb <=10) {
        printf("Le nombre %d est entre 0 et 10\n", nb);
    } else {
        printf("Le nombre %d n'est pas entre 0 et 10\n", nb);
    }

    return 0;
}
