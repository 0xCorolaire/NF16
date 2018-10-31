#include <stdio.h>
#include <stdlib.h>

/*Il est souvent pratique de définir un nœud factice
appelé sentinelle qui remplace les valeurs NIL du
prédécesseur de la tête ainsi que du successeur de
la queue de la liste. Ainsi, une liste doublement
chaînée avec sentinelle devient circulaire.
• Objectif : simplifier les conditions limites.*/

struct cellule {
    int cle;
    struct cellule * succ;
    struct cellule * pred;
};

/**
 * Création d'une liste doublement chainée vide (avec sentinelle)
 */
struct cellule * creerListeVide();
/**
 * Insertion d'une valeur en fin de liste chaînée
 * Retourne un pointeur vers la cellule insérée
 */
struct cellule * inserer(struct cellule * tete, int valeur);
/**
 * Suppression d'une cellule d'une liste chaînée
 */
void supprimer(struct cellule * cel);

void afficher(struct cellule * tete);

struct cellule * creerListeVide() {

    struct cellule * sentinelle = malloc(sizeof(struct cellule));

    sentinelle->cle = -1; // Valeur  arbitraire
    sentinelle->succ = sentinelle;
    sentinelle->pred = sentinelle;

    return sentinelle;
}

struct cellule * inserer(struct cellule * tete, int valeur) {
    // On suppose la liste non vide (elle contient au moins la sentinelle)
    // Crée une nouvelle cellule
    struct cellule * nouveau = malloc(sizeof(struct cellule));
    nouveau->cle = valeur;
    nouveau->succ = tete; // Son succ est la sentinelle
    nouveau->pred = tete->pred; // Son pred est l'ancien pred de la sentinelle
    tete->pred->succ = nouveau; // Le succ du pref de la sentinelle est nouveau
    tete->pred = nouveau; // Le pref de sentiennelle est nouveau

    return nouveau;
}

void supprimer(struct cellule * cel) {
    // On suppose que la cellule à supprimer n'est pas la sentinelle
    cel->pred->succ = cel->succ;
    cel->succ->pred = cel->pred;
    free(cel);
}

void afficher(struct cellule * tete) {
    struct cellule * current = tete->succ;

    while(current != tete) {
        printf("%d\n", current->cle); 
        current = current->succ;
    }
}


int main() {

    struct cellule * l = creerListeVide();
    inserer(l, 1);
    struct cellule * deux = inserer(l, 2);
    inserer(l, 3);
    afficher(l);
    supprimer(deux);
    afficher(l);
    return 0;
}
