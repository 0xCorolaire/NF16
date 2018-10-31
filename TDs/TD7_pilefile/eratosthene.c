#include <stdlib.h>
#include <stdio.h>

// On traite le cas où la valeur de n est saisie par l'utilisateur

// Un nombre premier possède deux diviseurs distincts : 1 et lui-même
int main() {

    // Marque à 0 les nombres premiers
    // Marque à 1 les nombres non premiers
    int n, i, j;
    scanf("%d", &n);

    int * tab = calloc(n+1, sizeof(int)); // Initialement tous les nombres marqués à 0
    tab[0] = 1; // 0 non premier
    tab[1] = 1; // 1 non premier
    // 2 est le plus petit nombre premier
 
    // Pour chaque valeur
    // - Si non marquée (valeur 0), elle n'est pas multiple d'un nombre plus petit (hormis 1)
    //   C'est donc un nombre premier
    // - Si marquée (valeur 1), ce n'est pas un nombre premier
    for(i=2; i<=n;i++) {
        // Si i est premier, on marque à 1 ses multiples
        if(!tab[i]) {
            printf("%d est premier\n", i);
            for(j=2*i;j<=n;j+=i) {
                tab[j] = 1; // Non premier
            } 
        } 
    }
    free(tab);

    return 0;




}
