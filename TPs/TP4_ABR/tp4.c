#include "TP4.h"

T_Noeud *abr_creer_noeud(int valeur){
  T_Noeud* newN = (T_Noeud*)malloc(sizeof(T_Noeud));
  if(newN==NULL){
    return NULL;
  }else{
    newN->key = valeur;
    newN->filsDroit = NULL;
    newN->filsGauche = NULL;
    return newN;
  }
}

//fonction de parcours prefixe d'un abr
void abr_prefixe(T_Arbre abr) {
	if (abr != NULL) {
		printf("Noeud --> %d \n",abr->key);
    if(abr->filsDroit==NULL && abr->filsGauche==NULL){
      printf("      --> FG : NULL -- FD : NULL\n");
    }else if(abr->filsGauche==NULL){
      printf("      --> FG : NULL -- FD : %d\n",abr->filsDroit->key);
    }else if(abr->filsDroit==NULL){
      printf("      --> FG : %d -- FD : NULL\n",abr->filsGauche->key);
    }else{
      printf("      --> FG : %d -- FD : %d\n", abr->filsGauche->key,abr->filsDroit->key);
    }
    abr_prefixe(abr->filsGauche);
    abr_prefixe(abr->filsDroit);
	}
	return;
}

void abr_inserer(int valeur,T_Arbre *abr){
  T_Noeud* newN = abr_creer_noeud(valeur);
  T_Arbre tmp2 = NULL;
  T_Arbre tmp = *abr;
  while(tmp != NULL){
    tmp2 = tmp;
    if(newN->key < tmp->key)
      tmp = tmp->filsGauche;
    else
      tmp = tmp->filsDroit;
  }
  if(tmp2 == NULL)
    *abr = newN;
  else if (newN->key < tmp2->key)
    tmp2->filsGauche = newN;
  else
    tmp2->filsDroit = newN;
  return;
}

void abr_supprimer(int valeur,T_Arbre *abr){
  T_Arbre toDelete=*abr;
  T_Arbre tempopere=*abr;
  while (toDelete!=NULL && valeur!=toDelete->key) {
      if(valeur < toDelete->key){
        toDelete = toDelete->filsGauche;
      }
      else{
        toDelete = toDelete->filsDroit;
      }
  }
  //toDelete est l'élement à supprimer. On va chercher maintenant le père de celui-ci pour pouvoir remplacer
  T_Arbre pere=*abr;
  if (toDelete == pere) {
      pere = NULL;
  }else{
    while(pere->filsDroit!=toDelete && pere->filsGauche!=toDelete){
        if(pere->key > toDelete->key){
          pere = pere->filsGauche;
        }
        else{
          pere = pere->filsDroit;
        }
    }
  }
  //On possède le père du noeud maintenant. S'il est null, simple on veut juste supprimer la racine
  if (pere == NULL){
      if(toDelete->filsGauche==NULL && toDelete->filsDroit==NULL){
        *abr=NULL;
      }
      else if(toDelete->filsGauche!=NULL && toDelete->filsDroit==NULL){
        *abr=toDelete->filsGauche;
      }
      else if(toDelete->filsGauche==NULL && toDelete->filsDroit!=NULL){
        *abr=toDelete->filsDroit;
      }
      else{
          //On va chercher le min du fils droit et on remplace par la valeur à supprimer et on supprimer definitivement ce minimum
          T_Noeud *successeur=toDelete->filsDroit;
          while (successeur->filsGauche!=NULL) {
              successeur=successeur->filsGauche;
          }
          toDelete->key=successeur->key;
          abr_supprimer(successeur->key,&(toDelete->filsGauche));
      }
  //Si on arrive là, on a un pere, donc ce n'est pas la racine.
} else if(toDelete->filsGauche==NULL && toDelete->filsDroit==NULL){
      tempopere = pere;
      if (toDelete == tempopere->filsDroit) {
          tempopere->filsDroit=NULL;
      } else {
          tempopere->filsGauche=NULL;
      }
      //La si il a un fils gauche, on donne au pere ce noeud
  }else if(toDelete->filsGauche!=NULL && toDelete->filsDroit==NULL){
      tempopere = pere;
      if(tempopere->filsDroit==toDelete){
        tempopere->filsDroit=toDelete->filsGauche;
      }
      else{
        tempopere->filsGauche=toDelete->filsGauche;
      }
      //Meme chose côté droit
  }else if(toDelete->filsGauche==NULL && toDelete->filsDroit!=NULL){
      tempopere = pere;
      if(tempopere->filsDroit==toDelete){
        tempopere->filsDroit=toDelete->filsDroit;
      }
      else{
        tempopere->filsGauche=toDelete->filsDroit;
      }
      //cas le plus dur : on a et fils droit , et fils gauche, on prend le min de son fils droit et on le remonte
  }else{
      T_Noeud * successeur = toDelete->filsDroit;
      while(successeur->filsGauche != NULL) {
          successeur=successeur->filsGauche;
      }
      toDelete->key=successeur->key;
      abr_supprimer(successeur->key,&(toDelete->filsDroit));
  }
}

void abr_clone(T_Arbre original, T_Arbre *clone, T_Noeud* parent) {
  if (original == NULL){
    printf("L'arbre a copier est null, Aucune utilité de copier un arbre nul.");
    return;
  }
  //Simple ici, on donne la racine au clone, puis on parcours l'original et attribuer à chaque fois le fd, fg en descendant danss l'arbre
  *clone = abr_creer_noeud(original->key);
  //Par recursivité, on classe les valeur. Si la nouvelle valeur est supérieure, on dit qu'elle devient son pere ( et devient fils gauche) vice versa
  if (parent != NULL)
      if (parent->key>(*clone)->key){
        parent->filsGauche=*clone;
      }
      else{
        parent->filsDroit=*clone;
      }
  //fait par recursivité, on parcours toutes les branches
  if (original->filsDroit!=NULL) {
      abr_clone(original->filsDroit,&((*clone)->filsDroit),*clone);
  }
  if (original->filsGauche!=NULL) {
      abr_clone(original->filsGauche, &((*clone)->filsGauche),*clone);
  }
}

void detruire_arbre(T_Arbre *abr){
  if (*abr == NULL){
    return;
  }
  detruire_arbre(&(*abr)->filsGauche);
  detruire_arbre(&(*abr)->filsDroit);
  *abr = NULL;
  return;
}

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
    if(arbre->filsGauche==NULL){
        printf("      --> FG(%d): NULL",arbre->boolG);
        return;
    }else if(arbre->filsDroit==NULL){
        printf("      --> FD(%d): NULL",arbre->boolD);
        return;
    }else{
        printf("Noeud --> %d\n",arbre->key);
        if(arbre->boolG!=1)
            printf("      --> FG(%d): %d",arbre->boolG,arbre->filsGauche->key);
        else
            printf("      --> FG(%d): %d",arbre->boolG,arbre->filsGauche->key);
        if(arbre->boolD!=1)
            printf(" -- FD(%d): %d\n",arbre->bdd,arbre->filsDroit->key);
        else
            printf(" -- FD(%d): %d\n",arbre->bdd,arbre->filsDroit->key);
        if(arbre->boolG==0)
            cousu_prefixe(arbre->filsGauche);
        if(arbre->boolD==0)
            cousu_prefixe(arbre->filsDroit);
    }
  }
  return;
}

void cousu_inserer(int valeur,T_Arbre_C *arbre){






  
}
