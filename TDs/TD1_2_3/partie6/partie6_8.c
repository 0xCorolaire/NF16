#include <stdio.h>
#include <string.h>
#define NMAX 100

int main() {

    char chaine[NMAX];

    printf("Veuillez saisir une chaine...\n");
    fgets(chaine, NMAX, stdin);

    printf("%s\n", chaine);

    int i = 0;
    while(chaine[i] != '\0') {
        printf("%c\n", chaine[i]);
        i++;
    }
    printf("La chaine fait %d caractères\n", i);
    printf("La chaine fait %d caractères\n", strlen(chaine));
    


    return 0;
}
