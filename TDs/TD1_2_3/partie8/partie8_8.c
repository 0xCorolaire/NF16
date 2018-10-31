#include <stdio.h>
#include <string.h> // Contient déclaration de strlen
#define NMAX 50


void maj(char * chaine);

int main() {

    char str[NMAX];
    printf("Veuillez entrer une chaine\n");
    scanf("%s", str); // str <=> &str[0] qui correspond à l'adresse du premier élément
    // &str correspond à l'adresse du tableau qui est identique à l'adresse du premier élément
    maj(str);
    printf("La chaine en majuscules est %s\n", str);
    
    return 0;
}

void maj(char * chaine) {
    int i;
    for(i=0; i<strlen(chaine); i++) { // while (chaine[i] != '\0') {
        if(chaine[i] >= 'a' && chaine[i] <= 'z') {
            chaine[i]-='a'-'A';
        }

    }

}
