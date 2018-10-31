#include <stdio.h>

// Déclaration de la fonction swap
void swap(int *a, int *b);
// En C, le passage de paramètres se fait par valeur. Pour pouvoir réellement changer les valeurs après le retour de la
// fonction, il est nécessaire de passeur leur adresse. D'où l'utilisation des pointeurs


int main() {
    
    int x, y;
    printf("Veuillez renseigner 2 entiers...\n");
    scanf("%d %d", &x, &y);
    printf("Avant swap, x vaut %d et y vaut %d\n", x, y);
    swap(&x, &y);
    printf("Après swap, x vaut %d et y vaut %d\n", x, y);


    return 0;
}

// Définition de la fonction swap
void swap(int *a, int *b) {
    
    int buffer;
    buffer = *a;
    *a = *b;
    *b = buffer;

}
