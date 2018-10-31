#include <stdio.h>
#define NMAX 5

int main() {


    char bjr1[] = {'b','o','n','j','o','u','r', '\0'};
    // Ne pas oublier le caractère de fin de chaine '\0' (permet de repérer ou se termine une chaine de caractères)!
    // Essayez de l'enlever pour voir ce qu'il se passe lorsqu'on effectue le printf
    printf("%s\n", bjr1);
    
    
    char bjr2[] = "bonjour"; // Quand même plus simple à écrire
    printf("%s\n", bjr2);


    return 0;
}
