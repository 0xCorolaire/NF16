#include "file.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Implantation par tableau en file tournante
/*Conventions :
– Tête[F] pointe sur le premier élément à défiler
– Queue[F] pointe sur le premier emplacement libre
– Initialement Tête[F]=Queue[F]=0
– Longueur[F] retourne la taille maximale de F
– On dit que la File est vide si Tête[F]=Queue[F]
– On dit que la File est pleine si
Tête[F]=modulo(Queue[F]+1, longueur[F])//
*/


file creerFile() {
    file f;
    f.tete = 0;
    f.queue = 0;
    return f;
}


int fileVide(file * f) {
    return (f->tete == f->queue);
}

int filePleine(file * f) {
    return (f->tete == (f->queue+1)%MAXF);
}

int enfiler(file * f, int val) {
    if(filePleine(f)) {
        printf("Erreur : file pleine\n");
        return 0;
    } else {
        f->tab[f->queue] = val;
        f->queue = (f->queue+1)%MAXF;
        return 1;
    }
}

int defiler(file * f) {
    int val;
    if(fileVide(f)) {
        return INT_MAX;
    } else {
        val = f->tab[f->tete]; // Récupère la valeur en tête
        f->tete = (f->tete+1)%MAXF;
        return val;
    }
}


void afficherFile(file f) {
    int i;
    while((i=defiler(&f))!=INT_MAX) {
        printf("%d\n", i);
    }

}
