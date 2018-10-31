#include <stdio.h>

int main() {
    int var, somme, count;
    float moyen;

    somme = 0;
    count = 0;
    do {
        printf("Veuillez saisir un entier strictement positif...\n");
        scanf("%d", &var);
        if(var >0) {
            printf("Valeur saisie : %d\n", var);
            count++; 
            somme+=var;
        } else if(var != -1) {
            printf("Erreur, %d n'est pas un entier strictement positif\n", var);
        }
       
    } while(var != -1);

    moyen = (float)somme/count;
    printf("La moyenne est de %f\n", moyen);
    return 0;
}
