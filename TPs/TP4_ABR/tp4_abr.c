#include "TP4_ABR.h"

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

void abr_inserer_recurs(int valeur, T_Arbre *abr){
    if((*abr)->key == valeur) printf("ERREUR: Valeur %d déjà présente dans l'arbre \n", valeur);
    if(*abr){
        if(valeur > (*abr)->key)
            if((*abr)->filsDroit) abr_inserer(valeur,&(*abr)->filsDroit);
            else (*abr)->filsDroit=abr_creer_noeud(valeur);
        else
            if((*abr)->filsGauche) abr_inserer(valeur, &(*abr)->filsGauche);
            else (*abr)->filsGauche = abr_creer_noeud(valeur);
    }
    else abr = abr_creer_noeud(valeur);
}

T_Noeud* abr_max(T_Arbre abr){
    if(abr){
        if(abr->filsDroit) return abr_max(abr->filsDroit);
        else return abr;
    }
    else return NULL;
}

/* Suppression d'un noeud à partir de sa valeur*/
void abr_supprimer(int valeur,T_Arbre *abr){
    if(!(*abr)) printf("La valeur n'est pas présente dans l'arbre \n"); //arbre vide
    else{
        if((*abr)->key > valeur) abr_supprimer(valeur, &(*abr)->filsGauche); //le noeud recherché se trouve dans la partie gauche
        else if((*abr)->key < valeur) abr_supprimer(valeur, &(*abr)->filsDroit); //le noeud recherché se trouve dans la partie droite
        else{ // sinon, on déduit que abr pointe vers le noeud à supprimer
            if((*abr)->filsGauche == NULL) (*abr) = (*abr)->filsDroit; // s'il n'y a pas de fils gauche, l'arbre droit remonte
            else if ((*abr)->filsDroit == NULL) (*abr) = (*abr)->filsGauche; //s'il n'y a pas de fils droit, l'arbre gauche remonte
            else{ //si le noeud possède un fils droit et un fils gauche
                    // le noeud prend la valeur du maximum de son arbre gauche
                T_Noeud* maxG = abr_max((*abr)->filsGauche);
                (*abr)->key = maxG->key;

                //on pense à supprimer l'ancien noeud qu'on a remonté
                abr_supprimer(maxG->key,&((*abr)->filsGauche));

                //on pense à libérer son espace mémoire ensuite
                free(maxG);
            }
        }
    }
}


/* Crée une copie de l'arbre entré en paramètre */
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

void detruire_arbre_alt(T_Arbre *abr){
    if((*abr)->filsGauche){
        printf("Destruction du fils gauche %d \n", (*abr)->filsGauche->key);
        detruire_arbre(&((*abr)->filsGauche));
        T_Noeud* tmp = ((*abr)->filsGauche);
        ((*abr)->filsGauche) == NULL;
        free(tmp);
    }
    if((*abr)->filsDroit){
        printf("Destruction du fils droit %d \n", (*abr)->filsDroit->key);
        detruire_arbre(&((*abr)->filsDroit));
        T_Noeud* tmp = ((*abr)->filsDroit);
        ((*abr)->filsDroit) == NULL;
        if((*abr)->filsDroit) printf("Wesh jcomprends R");
        free(tmp);
    }
    if(!((*abr)->filsGauche) && !((*abr)->filsGauche)) printf("Destruction du noeud %d \n", (*abr)->key);
}
