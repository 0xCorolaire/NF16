#include <stdio.h>

int main() {
    int var;
    do {
        printf("Veuillez saisir un entier strictement positif...\n");
        scanf("%d", &var);
        if(var >0) {
            printf("Valeur saisie : %d\n", var);
        } else if(var != -1) {
            printf("Erreur, %d n'est pas un entier strictement positif\n", var);
        }
       
    } while(var != -1);


    return 0;
}
