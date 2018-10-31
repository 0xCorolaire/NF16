#include <stdio.h>

int main() {

    int far;
    printf("Veuillez saisir une température en degré Fahrenheit (entier)...\n");
    scanf("%d", &far);
    
    float centig = 5/9.*(far-32);
    // largeur/gabarit : 5 => nombre min de caractères affichés
    // precision : 1 => nombre de chiffres de la partie décimale
    // j'ajoute des * pour bien voir le rôle du gabarit dans l'affichage du nombre
    printf("Far : %d\nCentig : *%5.1f*\n", far, centig);

    return 0;
}
