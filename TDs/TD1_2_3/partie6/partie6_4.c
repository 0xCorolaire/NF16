#include <stdio.h>

int main() {

    char c;
    do {

        printf("Veuillez saisir un caractère...\n");
        c = getchar();
        while(getchar() != '\n'); // Essayez de retirer cette ligne et exécuter le programme
        switch(c) {
            case 'o':
            case 'O':
            case 'n':
            case 'N':
            case '0':
            case '1':
            case '2':
            case '3':
                printf("C'est un bon caractère\n");
                break;
            default:
                printf("C'est un mauvais caractère\n");
        }
    } while(c != 'n' && c != 'N');

    return 0;
}
