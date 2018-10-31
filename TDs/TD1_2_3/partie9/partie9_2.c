#include <stdio.h>
#define NMAX 50

struct Un_Tableau_Entier {
    int tab[NMAX];
    int ncase; // Permet de mémoriser le nombre de cases du tableau réellement utilisées 
};

int main() {

    struct Un_Tableau_Entier tableau;
    tableau.ncase = 0;

    return 0;
}
