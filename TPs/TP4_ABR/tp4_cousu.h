#ifndef TP4_COUSU_H_INCLUDED
#define TP4_COUSU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "tp4_abr.h"
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
void cousu_infixe(T_Arbre_C *arbre);

//Transformation
void abr_to_cousu(T_Arbre abr, T_Arbre_C *clone, T_Noeud_C* parent);

#endif // TP4_COUSU_H_INCLUDED
