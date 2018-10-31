#include <stdio.h>
#define NMAX 7

int in_domain(int n, int lb, int ub);


int main() {

    int tab[NMAX] = {23, 76, 4, -9, 146, 867, 4};

    int inf, sup,i;
    printf("Veuillez saisir une borne inf...\n");
    scanf("%d", &inf);
    printf("Veuillez saisir une borne sup...\n");
    scanf("%d", &sup);

    printf("Valeurs dans l'intervalle [%d;%d]\n", inf, sup);
    for(i=0;i<NMAX;i++) {
        if(in_domain(tab[i], inf, sup) == 1) {
            printf("%d ", tab[i]);
        }
    }
    printf("\n");
    
    return 0;
}

int in_domain(int n, int lb, int ub) {
    if(n>=lb && n<=ub) 
        return 1;
    else
        return 0;
	// OU
	// return (n>=lb && n <= ub); // Renvoie 1 si la condition est vraie, 0 sinon
}
