#include <stdio.h>
#include <stdlib.h>


// On représente les personnes sous la forme d'une liste chaînée circulaire

struct noeud {
    int cle;
    struct noeud * succ;
};

// Déclarations
struct noeud * creerNoeud(int cle);
struct noeud * creerListe(int n);
void elimine(int n, int m);

// Définitions

struct noeud * creerNoeud(int cle) {
    // On pourrait tester la valeur renvoyée par malloc
    struct noeud * n = malloc(sizeof(struct noeud));
    n->cle = cle;
    return n;

}

/*
 * Crée une liste circulaire de n elements et renvoie un pointeur vers le noeud tête
 * struct noeud * creer_liste_circ(int n)
 * On suppose n>=1
 */
struct noeud * creerListe(int n) {
    int i;
    // Création du noeud tête
    struct noeud * tete = creerNoeud(1);
    // Prec nous permet de mémoriser le dernier noeud créé
    struct noeud * prec = tete;
    // Création du reste de la liste
    struct noeud * new;
    for(i=2; i<=n;i++) {
        new = creerNoeud(i); // Création du nouveau noeud
        prec->succ = new; // Ajout en fin de liste
        prec = new;
    }

    prec->succ = tete; // Liste circulaire, le dernier noeud créé a pour successeur la tête

    return tete; // Renvoie un pointeur vers la tête
}

/*
 * Détermine l'individu éliminé à chaque itération
 */
void elimine(int n, int m) {

    int i;
    // Création d'une liste chaînée circulaire de n éléments
    struct noeud * tete = creerListe(n);

    // Recherche la cellule qui a tête pour successeur
    struct noeud * pred = tete;
    while(pred->succ != tete) {
        pred= pred->succ;
    }
    /* Pour n= 9 et m=5
     * Initalement, pred contient un pointeur vers 9, soit l'élément qui a 1 comme successeur
     * ...=>1=>2=>3=>4=>5=>6=>7=>8=>[9]=>...
     * On cherche le m-1ème élément (le préd de l'élément à supprimer) => On avance de 4
     * ...=>1=>2=>3=>[4]=>5=>6=>7=>8=>9=>...
     * pred->succ = pred->succ->succ (suppression de 5)
     * ...=>1=>2=>3=>[4]=>6=>7=>8=>9=>...
     * On cherche le m-1ème élément (le préd de l'élément à supprimer) => On avance de 4
     * ...=>1=>2=>3=>4=>6=>7=>8=>[9]=>...
     * pred->succ = pred->succ->succ (suppression de 1)
     * ...=>2=>3=>[4]=>6=>7=>8=>[9]=>...
     *
     */

    // Tant que la liste n'est pas réduite à un seul élément
    while(pred->succ!=pred) {
        // On cherche le m-1ème élément (la cellule qui a pour successeur l'élément à supprimer)
        for(i=1;i<m; i++) { // Si m vaut 2, le pred est la cellule de tête 
            pred=pred->succ; // On avance 
        }
        struct noeud * tmp = pred->succ; // Enregistre l'adresse de la cellule supprimée
        pred->succ=pred->succ->succ; // Supprime la cellule de la liste
        printf("Elimination de %d\n", tmp->cle);
        free(tmp); // Libération de la mémoire
    }
    printf("Elimination de %d\n", pred->cle); // Elimination du dernier
    free(pred); // Libération de la mémoire  
}

int main() {
    elimine(9, 5);
    return 0;
}

