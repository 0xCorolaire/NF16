#include <stdio.h>

int main() {

    printf("Veuillez saisir un caractère...\n");

    switch(getchar()) {
        case '1':
            printf("C'est un\n");
            break;
        case '2':
            printf("C'est deux\n");
            break;
        case '3':
            printf("C'est trois\n");
            break;
        default:
            printf("C'est autre chose...\n");
    
    }

    return 0;
}
