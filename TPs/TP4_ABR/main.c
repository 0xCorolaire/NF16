#include <stdio.h>
#include <stdlib.h>
#include "tp4_abr.h"
#include "tp4_cousu.h"

int main()
{
    T_Arbre abr = NULL;
    T_Arbre clone = NULL;
    T_Arbre_C cousu = NULL;
    int valeur;
    int choix = 0;
    int working = 1;
    while(working){
        printf("\n");
        printf("1. Creer un ABR\n");
        printf("2. Afficher l'ABR en prefixe\n");
        printf("3. Inserer une valeur dans L'ABR\n");
        printf("4. Supprimer une valeur de l'ABR\n");
        printf("5. Cloner l'ABR\n");
        printf("6. Afficher le clone en prefixe\n");
        printf("7. Creer un arbre binaire cousu à partir d'un ABR\n");
        printf("8. Afficher l'abre binaire cousu en prefixe\n");
        printf("9. Afficher l'abre binaire cousu en infixe\n");
        printf("10. Inserer une valeur dans l'arbre binaire cousu\n");
        printf("11. Quitter\n");
        printf("\n");
        printf("Que voulez vous faire : ");
        scanf("%d", &choix);
        switch(choix){
            case 1 :
                printf("\nEntrez la racine : ");
                scanf("%d", &valeur);
                T_Arbre abr = abr_creer_noeud(valeur);
                break;

            case 2 :
                if(abr){abr_prefixe(abr);}
                else{
                    printf("L'arbre est vide");
                }
                break;

            case 3 :
                if(abr){
                    printf("\nEntrez une valeur a ajouter a l'arbre : ");
                    scanf("%d", &valeur);
                    abr_inserer(valeur, &abr);
                }else{
                    printf("\nl'ABR est vide, il faut entrer la racine d'abord (1)");
                }
                break;

            case 4:
                if(abr){
                    printf("\nEntrez la valeur à supprimer : ");
                    scanf("%d", &valeur);
                    abr_supprimer(valeur, &abr);
                }else{
                    printf("\nl'ABR est vide, il faut entrer la racine d'abord (1)");
                }
                break;

            case 5:
                if(abr){
                    abr_clone(abr, &clone, NULL);
                    if(clone){
                        printf("\nClone cree\n");
                        abr_prefixe(clone);
                    }else{
                        printf("\nProbleme lors de la creation du clone");
                    }
                }else{
                    printf("\nl'ABR est vide, il faut entrer la racine d'abord (1)");
                }
                break;

            case 6:
                if(clone){
                    abr_prefixe(clone);
                }else{
                    printf("\nAucun clone, il faut le creer (5)");
                }
                break;

            case 7:
                if(abr){
                    abr_to_cousu(abr, &cousu, NULL);
                    if(cousu){
                        printf("\nArbre cousu cree");
                    }else{
                        printf("\nErreur lors d passage de l'ARB au cousu");
                    }
                }else{
                    printf("\nl'ABR est vide, il faut entrer la racine d'abord (1)");
                }
                break;

            case 8:
                if(cousu){
                    cousu_prefixe(cousu);
                }else{
                    printf("\nl'ABR cousu n'est toujours pas cree, veuillez le creer d'abord (7)");
                }
                break;

            case 9:
                if(cousu){
                    cousu_infixe(&cousu);
                }else{
                    printf("\nl'ABR cousu n'est toujours pas cree, veuillez le creer d'abord (7)");
                }
                break;

            case 10:
                if(cousu){
                    printf("\nEntrez la valeur à ajouter dans l'arbre cousu : ");
                    scanf("%d", &valeur);
                    cousu_inserer(valeur, &cousu);
                }else{
                    printf("\nl'ABR cousu n'est toujours pas cree, veuillez le creer d'abord (7)");
                }
                break;

            case 11:
                if(abr){
                    printf("\nArbre detruit !");
                    detruire_arbre(&abr);
                }
                if(clone){
                    printf("\nArbre clone detruit !");
                    detruire_arbre(&clone);
                }
                if(cousu){
                    printf("\nArbre cousu detruit !");
                }
                working = 0;
                break;
            default:
                break;
        }
    }
    return 0;
}
