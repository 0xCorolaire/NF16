#include <stdio.h>
#include <stdlib.h>

#define NROW 3
#define NCOL 4 
int main() {

    // Toutes les notations avec des pointeurs
    int i,j;
    int ** tab = malloc(sizeof(int)*NROW);
    int val = 12;
    
    int ** pnt1 = tab;
    int * pnt2;

    for(i=0; i<NROW; i++) {
        pnt2 = malloc(sizeof(int)*NCOL);
        *pnt1 = pnt2;
        for(j=0; j<NCOL; j++) {
            *pnt2 = val;
            pnt2++;
            val++;
        }
        pnt1++;
    }

    pnt1 = tab;
    for(i=0; i<NROW; i++) {
        pnt2 = *pnt1;
        for(j=0; j<NCOL; j++) {
            printf("tab[%d][%d] = %d\n", i, j, *pnt2);
            pnt2++;
        }
        pnt1++;
    }
        

    // La mémoire allouée dynamiquement doit être libérée (malloc => free)
    pnt1 = tab;
    for(i=0; i<NROW; i++) {
        free(*pnt1);
        pnt1++;
    }
    free(tab);

    return 0;
}
