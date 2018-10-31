#include <stdio.h>

int main() {
    // On va le faire uniquement pour 3 variables : a, b et c
    int a,b,c,result;

    printf("Veuillez saisir 3 entiers...\n");
    scanf("%d %d %d", &a, &b, &c);

    result = a+b+c;

    printf("%d + %d + %d = %d\n", a, b, c, result);

    return 0;

}
