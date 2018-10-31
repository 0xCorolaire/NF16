#include <stdio.h>
#define NMAX 100

int main() {

    char chaine[NMAX];

    printf("Veuillez saisir une chaine...\n");
    fgets(chaine, NMAX, stdin);

    printf("%s\n", chaine);


    return 0;
}
