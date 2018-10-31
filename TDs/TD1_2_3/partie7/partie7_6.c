#include <stdio.h>
#define NMAX 5

int main() {

    int i,somme;
    int tab[NMAX];

    somme = 0;
    for(i=0; i<NMAX; i++) {
        printf("Veuillez saisir la valeur %d\n", i);
        scanf("%d", &tab[i]);
        somme += tab[i];
    }
    for(i=0; i<NMAX; i++) {
        printf("La valeur à l'indice %d  du tableau est %d\n", i, tab[i]);
    }
    printf("La somme vaut %d\n", somme);


    return 0;
}
