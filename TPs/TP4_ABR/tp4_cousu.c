#include "TP4_COUSU.h"
/*
------------PII : Arbres cousus ------------------
*/

T_Noeud_C *cousu_creer_noeud(int valeur){
  T_Noeud_C* newNc = (T_Noeud_C*)malloc(sizeof(T_Noeud_C));
  if(newNc==NULL){
    return NULL;
  }else{
    newNc->key=valeur;
    newNc->filsDroit=NULL;
    newNc->filsGauche=NULL;
    newNc->boolD=1;
    newNc->boolG=1;
    return newNc;
  }
}

void cousu_prefixe(T_Arbre_C arbre){
  if(arbre!=NULL){
    printf("Noeud --> %d\n",arbre->key);
    if(arbre->filsGauche!=NULL){
        printf("        --> FG (%d) : %d", arbre->boolG, arbre->filsGauche->key);
    }else{
        printf("        --> FG (%d) : NULL", arbre->boolG);
    }
    if(arbre->filsDroit!=NULL){
        printf(" -- FD (%d) : %d \n", arbre->boolD,arbre->filsDroit->key);
    }else{
        printf(" -- FD (%d) : NULL\n", arbre->boolD);
    }
    if(arbre->boolG==0){
        cousu_prefixe(arbre->filsGauche);
    }
    if(arbre->boolD==0){
        cousu_prefixe(arbre->filsDroit);
    }
  }
}

void cousu_inserer(int valeur,T_Arbre_C *arbre){
  T_Noeud_C* newNc=cousu_creer_noeud(valeur);
  T_Arbre_C tmp2=NULL;
  T_Arbre_C tmp=*arbre;
  if(tmp==NULL){
    //On peut créer la valeur
    tmp=cousu_creer_noeud(valeur);
  }else if(valeur<tmp->key){
    if(tmp->boolD==1){
        newNc->filsGauche=tmp->filsGauche;
        newNc->filsDroit=tmp;
        tmp->filsGauche=newNc;
        tmp->boolG=0;
    }else{
        cousu_inserer(valeur,&tmp->filsGauche);
    }
  }else if(valeur>tmp->key){
    if(tmp->boolD==1){
        newNc->filsDroit=tmp->filsGauche;
        newNc->filsGauche=tmp;
        tmp->filsDroit=newNc;
        tmp->boolD=0;
    }else{
        cousu_inserer(valeur,&tmp->filsDroit);
    }
  }
  *arbre=tmp;
}
