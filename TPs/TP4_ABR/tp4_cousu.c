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

//En recursif
void cousu_inserer(int valeur,T_Arbre_C *arbre){
  T_Arbre_C tmp=*arbre;
  if(tmp==NULL){
    //On peut créer la valeur
    tmp=cousu_creer_noeud(valeur);
  }else if(valeur<tmp->key){
    //Si find de l'arbre
    if(tmp->boolG==1){
        T_Arbre_C newNc=cousu_creer_noeud(valeur);
        newNc->filsGauche=tmp->filsGauche;
        newNc->filsDroit=tmp;
        tmp->filsGauche=newNc;
        tmp->boolG=0;
    }else{
        //Sinon on recursif
        cousu_inserer(valeur,&tmp->filsGauche);
    }
  }else if(valeur>tmp->key){
    //pareil
    if(tmp->boolD==1){
        T_Arbre_C newNc=cousu_creer_noeud(valeur);
        newNc->filsDroit=tmp->filsGauche;
        newNc->filsGauche=tmp;
        tmp->filsDroit=newNc;
        tmp->boolD=0;
    }else{
        cousu_inserer(valeur,&tmp->filsDroit);
    }
  }
  //On affecte la valeur
  *arbre=tmp;
}

//Affichage infixe
void cousu_infixe(T_Arbre_C *arbre){
  T_Arbre_C tmp=*arbre;
  //On part du noeud le + a gauche
  while(tmp->filsGauche != NULL){
        tmp=tmp->filsGauche;
  }
  //On va jusqu'au noeud max
  while(tmp->filsDroit!=NULL){
    printf("Noeud --> %d\n", tmp->key);
    if (tmp->filsGauche != NULL){
        printf("        --> FG (%d) : %d", tmp->boolG, tmp->filsGauche->key);
    }
    else {
        printf("        --> FG (%d) : NULL", tmp->boolG);
    }
    if (tmp->filsDroit!=NULL){
        printf(" -- FD (%d) : %d\n", tmp->boolD, tmp->filsDroit->key);
    }
    else{
        printf(" -- FD (%d) : NULL\n", tmp->boolD);
    }
    //Si on a plus de successeur -> on pointe sur le successeur
    if(tmp->boolD == 1){
        tmp=tmp->filsDroit;
    }
    //Sinon on check si le fD a des saG
    else if(tmp->boolD==0){
      tmp=tmp->filsDroit;
      //Tant qu'il a un fg
      while(tmp->boolG!=1){
        tmp=tmp->filsGauche;
      }
    }
  }
  //Une fois terminé, on doit afficher le dernier noeud
  printf("Noeud --> %d\n", tmp->key);
  if (tmp->filsGauche!=NULL){
    printf("        --> FG (%d) : %d", tmp->boolG, tmp->filsGauche->key);
  }
  else {
    printf("        --> FG (%d) : NULL", tmp->boolG);
  }
  if (tmp->filsDroit!=NULL){
    printf(" -- FD (%d) : %d\n", tmp->boolD, tmp->filsDroit->key);
  }
  else {
    printf(" -- FD (%d) : NULL\n", tmp->boolD);
  }
}
