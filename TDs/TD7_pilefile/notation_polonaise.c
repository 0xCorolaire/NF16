#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

/**
 * Expression en écriture polonaise inversée passée sous la forme d'une chaîne de caractères
 */
int calcul(char * exp) {
   
    pile p = creerPile();
    int k = 0;
    int nb, nb1, nb2, res;
    
    // 3 cas à gérer en parcourant la chaîne de cractères:
    // - C'est un opérande => On extrait le nombre et on l'empile
    // - C'est un espace => On avant au caractère suivant
    // - C'est un opérateur => On dépile 2 valeurs, on applique l'opérateur et on empile le résultat
    while(exp[k]!='\0') {
        // Si c'est le début d'un nombre
        if(exp[k]>='0' && exp[k]<='9') {
            nb = 0;
            /* Extraction du nombre */
            while(exp[k]>='0' && exp[k]<='9') {
                nb=nb*10;
                nb = nb+(exp[k]-'0');
                k++;
            }
            empiler(&p, nb); // Empiler le nombre
        } else { // Sinon c'est un espace ou un opérateur
            // Si c'est un opérateur
            if(exp[k]!=' ') {
                nb1 = depiler(&p);
                nb2 = depiler(&p);
                switch(exp[k]) {
                    case '+':
                        res = nb1+nb2;
                        break;
                    case '-':
                        res = nb1-nb2;
                        break;
                    case '*':
                        res = nb1*nb2;
                        break;
                    case '/':
                        res = nb1/nb2;
                        break;
                }
                empiler(&p, res); // Empiler le résultat
            }
            k++; // Passage au caractère suivant
        }
    }
    // Le résultat final est en haut de la pile 
    return depiler(&p);
}


int main() {
    printf("Resultat = %d\n", calcul("5 9 8 + 4 6 * * 7 + *"));
    return 0;
}
