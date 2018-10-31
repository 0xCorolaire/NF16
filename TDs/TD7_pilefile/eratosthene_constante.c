#include <stdlib.h>
#include <stdio.h>

#define N 100


int main() {

    // Marque à 0 les nombres premiers
    // Marque à 1 les nombres non premiers
    int i, j;

    int tab[N+1];
    for(i=0; i<=N; i++) {
        tab[i] = 0;
    }

    tab[0] = 1; // 0 non premier
    tab[1] = 1; // 1 non premier
    // 2 est le plus petit nombre premier

    for(i=2; i<=N;i++) {
        // Si i est premier, on barre ses multiples
        if(!tab[i]) {
            printf("%d est premier\n", i);
            for(j=2*i;j<=N;j+=i) {
                tab[j] = 1; // Non premier
            } 
        } 
    }

    return 0;




}
