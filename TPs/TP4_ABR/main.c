#include <stdio.h>
#include <stdlib.h>
#include "tp4_abr.h"
#include "tp4_cousu.h"

int main()
{
    T_Arbre abr = NULL;
    T_Arbre abrc = NULL;
    abr_inserer(5, &abr);
    abr_inserer(8, &abr);
    abr_inserer(25, &abr);
    abr_inserer(13, &abr);
    abr_inserer(39, &abr);
    abr_inserer(1, &abr);
    abr_inserer(45, &abr);
    abr_inserer(21, &abr);
    abr_supprimer(25, &abr);
    abr_prefixe(abr);
    printf("\n\n\n");
    abr_clone(abr,&abrc,NULL);
    detruire_arbre(&abr);
    abr_prefixe(abrc);

    printf("---------------------------------------\n");
    T_Arbre_C arbre_cousu = NULL;
    cousu_inserer(11, &arbre_cousu);
    cousu_inserer(2, &arbre_cousu);
    cousu_inserer(13, &arbre_cousu);
    cousu_inserer(1, &arbre_cousu);
    cousu_inserer(6, &arbre_cousu);
    cousu_inserer(17, &arbre_cousu);
    cousu_inserer(15, &arbre_cousu);
    cousu_infixe(&arbre_cousu);


    return 0;
}
