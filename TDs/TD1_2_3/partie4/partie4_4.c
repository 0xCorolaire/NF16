#include <stdio.h>

int main() {

    char x;
    printf("Veuillez saisir un caractère...\n");
    scanf("%c", &x);

    if(x >= '0' && x <= '9') {
        printf("C'est un nombre\n");
    } else if(x >= 'a' && x <= 'z') {
        printf("C'est entre a et z\n");
    } else if(x >= 'A' && x <= 'Z') {
        printf("C'est entre A et Z\n");
    }

    return 0;
}
