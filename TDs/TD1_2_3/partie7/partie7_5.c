#include <stdio.h>
#define NMAX 5

int main() {


    char bjr[] = "bonjour"; // Quand même plus simple à écrire
    printf("%s\n", bjr);

    // On parcourt le tableau de caractères
    // Tant que on n'a pas trouvé le caractère fin de chaine
    int i=0;
    while(bjr[i]!='\0') {
        printf("%c\n", bjr[i]);
        i++;
    }
    // bjr est un tableau de caractères
    bjr[1] = 'a';
    bjr[2] = 'd';

    printf("%s\n", bjr);


    return 0;
}
