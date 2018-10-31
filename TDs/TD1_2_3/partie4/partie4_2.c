#include <stdio.h>

int main() {

    int nb;
    printf("Veuillez saisir un nombre...\n");
    scanf("%d", &nb);



    if((nb>=7 && nb <=20) || nb == 127) {
        printf("Le nombre %d est OK\n", nb);
    } else {
        printf("Le nombre %d est KO\n", nb);
    }

    return 0;
}
