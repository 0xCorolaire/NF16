#include <stdio.h>
#define NMAX 10

int compte(int * tab);

int main() {

   int tab1[NMAX];
   int resultat = compte(tab1);

    printf("%d valeurs ont été saisies\n", resultat);

    return 0;
}


int compte(int * tab) {
   
    int nb,i;
    printf("Veuillez donner le nombre d'éléments à lire\n");
    scanf("%d", &nb);
    for(i=0; i<nb; i++) {
        printf("Valeur de l'élément %d : \n", i);
        scanf("%d", &tab[i]);
    }
    return nb;
}
