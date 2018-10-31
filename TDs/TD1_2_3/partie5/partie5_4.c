#include <stdio.h>

int main() {
    // On va le faire uniquement pour 3 variables : a, b et c
    int a,b,c,result, prod;
    float moyen;
    printf("Veuillez saisir 3 entiers...\n");
    scanf("%d %d %d", &a, &b, &c);

    result = a+b+c;

    printf("%d + %d + %d = %d\n", a, b, c, result);
    moyen = result/3.; // Attention à ne pas faire result/3 => entier
    printf("La moyenne vaut %f\n", moyen);
    prod = a*b*c;
    printf("Le produit vaut %d\n", prod);
    return 0;

}
