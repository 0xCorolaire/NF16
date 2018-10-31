#include <stdio.h>

int main() {

    int far;
    printf("Veuillez saisir une température en degré Fahrenheit (entier)...\n");
    scanf("%d", &far);
    
    float centig = 5/9.*(far-32);
    printf("Far : %d\nCentig : %f\n", far, centig);

    return 0;
}
