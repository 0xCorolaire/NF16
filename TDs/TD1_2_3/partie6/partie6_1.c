#include <stdio.h>

int main() {

    int i;
    for(i=0; i<=9; i++) {
        printf("Boucle for : %d\n", i);
    }
    printf("Après la boucle for, i vaut %d\n", i);
    
    i = 0;
    do {
        printf("Boucle do/while : %d\n", i);
        i++;
    } while(i<=9);
    printf("Après la boucle do/while, i vaut %d\n", i);
    
    i=0;
    while(i<=9) {
        printf("Boucle while : %d\n", i);
        i++;
    }
    printf("Après la boucle while, i vaut %d\n", i);



    return 0;
}
