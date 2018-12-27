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


/*
Définir la structure Noeud_C et le type correspondant T_Noeud_C qui représente un nœud d’un arbre
binaire cousu contenant une valeur entière. Entre autres, la structure devra contenir un booléen (int ou
char) pour indiquer si le pointeur droit d’un nœud est son successeur infixe ou non, et de même pour le
pointeur gauche.
2. Définir le type T_Arbre_C - de type pointeur vers une structure Noeud_C - qui servira à représenter l’arbre
binaire cousu.*/






#endif // TP4_H_INCLUDED
