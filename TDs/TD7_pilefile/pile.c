#include "pile.h"


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

pile creerPile() {
    pile p;
    p.sommet = -1; // Pile initialement vide
    return p;
}

int pileVide(pile * p) {
    if(p->sommet == -1) {
        return 1;
    } else {
        return 0;
    }
}

int pilePleine(pile * p) {
    if(p->sommet == MAXP-1) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Renvoie 0 si la pile est pleine, 1 sinon
 */
int empiler(pile * p, int val) {
    if(pilePleine(p)) {
        printf("Erreur : Pile pleine\n");
        return 0;
    } else {
        p->sommet++;
        p->tab[p->sommet] = val;
        return 1;
    }
}


/**
 * Renvoie la valeur qui vient d'être dépilée (INT_MAX si la pile était vide)
 */
int depiler(pile * p) {
    if(pileVide(p)) {
        return INT_MAX;
    } else {
        p->sommet--;
        return p->tab[p->sommet+1];
    }
}

/**
 * Affiche la pile en commençant par le sommet
 */
void afficherPile(pile p) {
    int i;
    while((i=depiler(&p))!=INT_MAX) {
        printf("%d\n", i);
    }
}

