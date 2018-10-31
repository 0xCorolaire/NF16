#include <stdio.h>

#define TAILLE 3

void truc(int *a, int b) {
    int i;
    for(i=0; i<b; i++) {
        *(a+i) = a[i] + 1; // a[i] = a[i]+1 // a[i]++
    }
}

int main() {

   int tab[TAILLE], i, *p;
   p = &tab[0]; // Adresse du premier élément du tableau. Peut être exprimé sous la forme tab qui donne l'adresse du tableau
   for(i=0; i<TAILLE; i++) {
    *(p+i) = i; // p[i]
   }
   
   printf("Contenu du tableau avant appel :\n");
   for(i=0; i<TAILLE; i++) {
        printf("%d\n", tab[i]);
   }
   truc(tab, TAILLE);
   // Incrémente la valeur de chaque élément du tableau de 1

   printf("Contenu du tableau après appel :\n");
   
   for(i=0; i<TAILLE; i++) {
       printf("%d\n", tab[i]);
   }
   return 0;
}
