#include <stdio.h>
#define NMAX 5

int main() {

    int tab1[NMAX] = {4, 3, 2, 1, 0};
    int tab2[] = {4, 3, 2, 1, 0}; // Si le tableau est initialisé, il n'est pas nécessaire d'expliciter la taille à la déclaration
   
    int i;
    for(i=0; i<NMAX; i++) {
        printf("tab1[%d] = %d\n", i, tab1[i]);
        printf("tab2[%d] = %d\n", i, tab2[i]);
    }


    return 0;
}
