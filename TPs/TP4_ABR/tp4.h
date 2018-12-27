#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED
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

//PII : ARBRE BINARIE COUSUS

typedef struct Noeud_C{
    int key;
    struct Noeud_C* filsGauche;
    struct Noeud_C* filsDroit;
    int boolD;
    int boolG;
}T_Noeud_C;

typedef T_Noeud_C* T_Arbre_C;

T_Noeud_C *cousu_creer_noeud(int valeur);
void cousu_prefixe(T_Arbre_C arbre);

//Insertion
void cousu_inserer(int valeur,T_Arbre_C *arbre);



#endif // TP4_H_INCLUDED
