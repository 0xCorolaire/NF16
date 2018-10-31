#include <stdio.h>
#define NMAX 5

int main() {

    int i,somme;
    int tab[NMAX];
    float moyen;

    somme = 0;
    for(i=0; i<NMAX; i++) {
        printf("Veuillez saisir la valeur %d\n", i);
        scanf("%d", &tab[i]);
        somme += tab[i];
    }
    moyen = (float)somme/NMAX;

    for(i=0; i<NMAX; i++) {
        printf("La valeur à l'indice %d  du tableau est %d\n", i, tab[i]);
        if(tab[i]>=moyen) {
            printf("La valeur %d est supérieure à la moyenne (%f)\n", tab[i], moyen);
        }
    }
    printf("La somme vaut %d\n", somme);


    return 0;
}
