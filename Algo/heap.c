#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

//Structure de tas
typedef struct Heap{
  int T[MAX];
  int taille;
} * heap;

heap newHeap(){
  //crée un nouveau tas vide
  heap new = (heap)malloc(sizeof(struct Heap));
  new->taille = -1;
  return new;
}

int racine(heap h){
  //retourne la valeur de la racine
  return h->T[0];
}

int pere(int i){
  //retourne l'indice du père du noeud d'indice i
  return i/2-1;
}

int gauche(int i,int taille){
  /*retourne l'indice du fils gauche du noeud d'indice i
  0 si le noeud n'existe pas*/
    return (2*i+1)*(2*i+1 <= taille);
}

int droite(int i,int taille){
  /*retourne l'indice du fils droit du noeud d'indice i
    0 si le noeud n'existe pas*/
    return (2*i+2)*(2*i+2 <= taille);
}

int isALeaf(int i, int taille){
  /*retourne 1 si le noeud est une feuille ; 0 sinon */
  return (i >= taille/2 +1 && i <= taille);
}

void entasser(heap h, int i){
  /*permet de construire un tas si les deux fils sont des tas*/
  int l = gauche(i,h->taille);
  int r = droite(i,h->taille);
  //on cherche le max ici
  int max = i;
  // sleep(1);
  // printf("i=%d : %d ; l=%d : %d ; r=%d : %d ; \n",i,h->T[i],l,h->T[l],r,h->T[r] );
  if (l != 0 && h->T[l] > h->T[i])
    max = l;
  if (r != 0 && h->T[r] > h->T[max])
    max = r;
  if (max != i){//si le max n'est pas à la position i
    //on échange les noeuds de position max et i
    int temp = h->T[max];
    h->T[max] = h->T[i];
    h->T[i] = temp;

    entasser(h,max); //on entasse à partir du noeuds d'indice max
  }
  return;
}

// Non fonctionnelle car il faudrait traiter les sous arbre en [A]
int insertionHeap(heap h, int cle){
  if (h->taille > MAX - 1){
    printf("Impossible d'insérer : heap rempli\n");
    return 1;
  }
  h->T[++(h->taille)] = cle;
  int i = h->taille;
  printf("i : %d\n",i);
  printf("pere(i) : %d\n",pere(i));
  while(pere(i) != 0){
    i = pere(i);
    // entasser(h,i); [A]
  }
  return 1;
}

int isAHeap(heap h,int i){
  /* renvoie 1 si la structure est effectivement un tas, O sinon */
  int g = gauche(i,h->taille);
  int d = droite(i,h->taille);
  int j = i,l=0;
  while(j != 0){
    j/=2;
    l++;
  }
  for(j = 0;j<l;j++)
    printf("~");
  printf("i : %d; (g,d) = (%d,%d)\n",i,g,d);
  if (!g || !d){
    if (!g && !d)
      return 1;
    else if (!g && h->T[i] > h->T[d])
      return isAHeap(h,d);
    else if (!d && h->T[i] > h->T[g])
      return isAHeap(h,g);
  }
  else if (h->T[i] > h->T[g] && h->T[i] > h->T[d])
    return isAHeap(h,g)*isAHeap(h,d);
  else{
    printf("STOP \n");
    return 0;
    }
}

heap construireHeap(int tab[MAX]){
  /* on construit un tas à partir d'un tableau */
  if (*tab == 0){
    printf("Le tableau est vide\n");
    return NULL;
  }
  int t = -1; //taille initiale du tableau
  heap new = newHeap();
  while (tab[++t]!=0);
  int l = new->taille = t-1;
  while(isALeaf(l, new->taille)){
    new->T[l] = tab[l];
    l--;
  }
  while(l>=0){
    // printf("Insertion de %d\n",tab[l]);
    new->T[l] = tab[l];
    entasser(new,l);
    l--;
  }
  return new;
}

void heapSort(int tab[MAX]){
  /* permet de trier un tableau avec un tas */

  heap h = construireHeap(tab);
  int i,j;
  int l = h->taille;
  for(i=l;i>0;i--){
    tab[i] = h->T[0];
    h->T[0] = h->T[i];
    (h->taille)--;
    // for(j=0; j<i ; j++)
    //   printf("h->T[%d] = %d\n",j,h->T[j]);
    // for(j=i; j<= l ; j++)
    //   printf("tab[%d] = %d\n",j,tab[j]);
    entasser(h,0);
  }
  tab[0] = h->T[0];
  free(h);
  return;
}

int calculerTaille(int * tab){
  int i = -1;
  while (tab[++i] != 0);
  return i-1;
}

int main(int argc, char const *argv[]) {
  int tab[MAX]={2,23,13,43,16,8,-1,-34,7,9};
  // int tab[MAX]={16,14,10,8,7,9,3,2,4,6};
  heapSort(tab);
  int i;
  printf("taille : %d\n",calculerTaille(tab));
  for(i=0 ; i <= calculerTaille(tab) ; i++)
     printf("%d\n",tab[i]);
  // for(i = 1; i < 60; i +=5){
  //   printf("\n%d, père : %d, g : %d, d : %d",i,pere(i),gauche(i,h->taille),droite(i,h->taille) );
  //   printf("\nEst-ce que le noeud d'indice %d est une feuille dans un tas de %d éléments ? %d\n",i,h->taille,isALeaf(i,h->taille));
  // }
  // int t = 10;
  // printf("\n Is a heap ? %d\n",isAHeap(h,0));
}
