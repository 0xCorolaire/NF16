#include <stdio.h>

int main() {

    int var;
    printf("Veuillez saisir un entier...\n");
    scanf("%d", &var);
    if(var%7==0) {
        printf("%d est divisible par 7\n", var);
    } else {
        printf("Le reste de la division de %d par 7 est %d\n", var, var%7);
    }

    return 0;
}
