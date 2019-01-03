#ifndef TP4_ABR_H_INCLUDED
#define TP4_ABR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//PI : ARBRE BINAIRE
typedef struct Noeud
{
    int key;
    struct Noeud* filsGauche;
    struct Noeud* filsDroit;
}T_Noeud;

typedef T_Noeud* T_Arbre;

T_Noeud *abr_creer_noeud(int valeur);
void abr_prefixe(T_Arbre abr);
//Insertion/suppression
void abr_inserer(int valeur,T_Arbre *abr);
void abr_supprimer(int valeur,T_Arbre *abr);
//Copie
void abr_clone(T_Arbre original, T_Arbre *clone, T_Noeud* parent);
//destruction
void detruire_arbre(T_Arbre *abr);


#endif // TP4_ABR_H_INCLUDED
