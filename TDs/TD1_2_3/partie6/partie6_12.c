#include <stdio.h>

int main() {

    char x; // On va demander à l'utilisateur de saisir un caractère (spécifié dans l'énoncé) même si cela n'a pas d'intérêt pratique
    int tab,i;
    do {
        printf("Quelle table de multiplication (tapez 0 pour sortir) ?\n");
        x = getchar();
        while(getchar() != '\n'); // On vide le buffer
        if(x > '0' && x <= '9') {
            tab = x - '0'; // récup l'entier correspondant au car
            for(i=0; i<=9; i++) {
                printf("%d * %d = %d\n", i, tab, i*tab);
            }
        } else if(x != '0') {
            printf("Ce n'est pas dans les possibilités du programme\n");
        
        }
    } while(x != '0');

    return 0;
}
