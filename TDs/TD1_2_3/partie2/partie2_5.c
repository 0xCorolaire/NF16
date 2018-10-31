#include <stdio.h>

int main() {

    float a, b, somme;
    printf("Entrez deux réels...\n");
    scanf("%f %f", &a, &b);
    somme = a+b;
    printf("\na vaut %f et b vaut %f.\nLa somme vaut %f\n", a, b, somme);

    return 0;
}
