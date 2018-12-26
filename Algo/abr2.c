#include <stdio.h>
#include <stdlib.h>
#define MAX 50

/*La transformation inverse de Rotd est une rotation gauche. En supposant qu’un sommet de
l’arbre porte les champs « g », « d »et « pere », écrire les algorithmes correspondant à une
rotation gauche et une rotation droite qui mettent à jour ces informations.*/

typedef struct node {
  int cle;
  struct node * pere;
  struct node * g;
  struct node * d;
} Node ;

typedef Node * arbre;

void insererABR(arbre * t, int k){
  arbre z = (arbre)malloc(sizeof(Node));
  z->cle = k;
  z->pere = NULL;
  arbre y = NULL;
  arbre x = * t;
  while (x != NULL) {
    y = x;
    if (z->cle < x->cle)
      x = x->g;
    else
      x = x->d;
  }

  if (y == NULL) //si l'arbre est vide
    *t = z;
  else if (z->cle < y->cle)
    y->g = z;
  else
    y->d = z;

  z->pere =y;
  return;
}

arbre rotD(arbre A, arbre x){
  if (x->g == NULL){ //s'il n'y a pas de fils gauche
    return x;
  }
  arbre y = x->g; //on récupère le noeud à remonter
  x->g = y->d; //on passe le sous-sous-arbre au noeud initial
  y->d = x; //on bascule ce noeud initial à droite de y
  if (x == A){ //si x est la racine
    return y; //y devient racine
  }
  else{ //sinon, x possède un père
    y->pere = x->pere; //le père de y devient celui de x
    if (x->pere->g == x) //y devient le fils du père de x
      x->pere->g = y;
    else
      x->pere->d = y;
  }
  x->pere = y; //le père de x est y
  if (x->g != NULL)
    x->g->pere = x;
  return A; //on renvoie le nouveau noeud enraciné
}

arbre rotG(arbre A,arbre y){
  if (y->d == NULL){ //s'il n'y a pas de fils droit
    return y;
  }
  arbre x = y->d; //on récupère le noeud à remonter
  y->d = x->g; //on passe le sous-sous-arbre au noeud initial
  x->g = y; //on bascule ce noeud initial à gauche de y
  if (y == A){ //si y est la racine
    return x; //x devient racine
  }
  else{ //sinon, y possède un père
    x->pere = y->pere; //le père de x devient celui de y
    if (y->pere->g == y)  //x devient le fils du père de y
      y->pere->g = x;
    else
      y->pere->d = x;
  }
    y->pere = x; //le père de y est x
  if(y->d != NULL)
    y->d->pere = y;
  return A; //on renvoie le nouveau noeud enraciné
}


void parcoursInfixe(arbre tree,int i) {
  if (tree != NULL) {
    parcoursInfixe(tree->g, i+1);
    int j;
    for(j=0;j<i;j++)
      printf("--");
    printf("%d\n",tree->cle);
    parcoursInfixe(tree->d,i+1);
  }
  return;
}

arbre enraciner(arbre A, int x){
  if (A == NULL)
    return A;

  if (A->cle < x){
    A->d = enraciner(A->d,x);
    return rotG(A,A);
  }
  else if (A->cle > x){
    A->g = enraciner(A->g,x);
    return rotD(A,A);
  }
  else
    return A;
}

int main(int argc, char const *argv[]) {
  arbre monABR;
  insererABR(&monABR,14);
  insererABR(&monABR,16);
  insererABR(&monABR,12);
  insererABR(&monABR,13);
  insererABR(&monABR,4);
  insererABR(&monABR,5);
  insererABR(&monABR,6);
  parcoursInfixe(monABR,0);

  monABR = rotD(monABR,monABR->g);
  printf("\n");
  parcoursInfixe(monABR,0);

  monABR = rotG(monABR,monABR->g);
  printf("\n");
  parcoursInfixe(monABR,0);
  printf("\n");
  monABR = enraciner(monABR,12);
  parcoursInfixe(monABR,0);

  return 0;
}
