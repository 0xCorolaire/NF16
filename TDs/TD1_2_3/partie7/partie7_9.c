#include <stdio.h>
#include <stdlib.h>

#define NROW 3
#define NCOL 4 
int main() {

    // On va utiliser des pointeurs pour les colonnes

    int * tab[NROW];
    int val = 12;
    int i, j;

   
    
    for(i=0; i<NROW; i++) {

        // Allocation dynamique de mémoire, renvoie l'adresse mémoire du bloc alloué
        tab[i] = malloc(sizeof(int)*NCOL);

        for(j=0; j<NCOL; j++) {
            tab[i][j] = val;
            val++;
        }
    }

   
    for(i=0; i<NROW; i++) {
        for(j=0; j<NCOL; j++) {
            printf("tab[%d][%d] = %d\n", i, j, tab[i][j]);
        }
    }
        

    // La mémoire allouée dynamiquement doit être libérée (malloc => free)
    for(i=0; i<NROW; i++) {
        free(tab[i]);
    }

    return 0;
}
