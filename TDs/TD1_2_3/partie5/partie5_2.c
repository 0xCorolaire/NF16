#include <stdio.h>

int main() {

    float a = 5/2; // Expression entre entiers => Entier
    printf("a vaut %f\n", a);
    a = 5.0/2;
    printf("a vaut %f\n", a);
    a = 5/2.0;
    printf("a vaut %f\n", a);
    a = (float)5/2;
    printf("a vaut %f\n", a);
    a = 5/(float)2;
    printf("a vaut %f\n", a);

    return 0;

}
