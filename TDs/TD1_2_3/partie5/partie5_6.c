#include <stdio.h>

int main() {

    char x;
    char diff = 'a' - 'A';
    
    printf("Veuillez saisir un caractère....\n");
    scanf("%c", &x);

    if(x >= 'a' && x <= 'z') {
        x-='a'-'A';
    }
    printf("Le caractère après modification est %c\n", x);


    
    return 0;

}
