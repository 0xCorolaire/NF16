#include <stdio.h>

int main() {
    
    int year;
    printf("Veuillez saisir une année...\n");
    scanf("%d", &year);
    // Année bissextile si :
    // si l'année est divisible par 4 et non divisible par 100, ou
    // si l'année est divisible par 400.

    if((year%4==0 && year%100 != 0) || year%400==0) {
        printf("L'année %d est bissextile\n", year);
    } else {
        printf("L'année %d n'est pas bissextile\n", year);
    }


    
    return 0;

}
