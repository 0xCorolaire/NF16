#include <stdio.h>
#include <stdlib.h>

#define MAX 100


void afficherTab(int n, int tab[n]){
  int i;
  for(i=0; i < n ; i++){
    printf("tab[%d] = %d\n",i,tab[i] );
  }
  return;
}

void insertionSort(int n,int tab[n]){
  /* Tri par insertion : on procède par décalage de valeur.
    La version de ce tri est stable */
  int i,j,temp;
  for(i=0; i < n ; i++){//on parcourt le tableau en entier
    j=i; //j permet le parcourt arrière pour l'insertion
    temp = tab[i]; //on sauvegarde la valeur à inserer
    while(j > 0 && temp < tab[j-1]){ //si la valeur précédente est plus grande
      tab[j] = tab[--j]; // on décale NOTE : ici le < permet la stabilité du tri
    }
    tab[j] = temp; //on insère
  }
  return;
}

void bubbleSort(int n, int tab[n]){
  /* Tri à bulles ; la version de ce tri est stable*/
  int i,temp,aTrier = 1;
  while (aTrier) {
    aTrier =0;
    for(i=0;i<n-1;i++){
      if (tab[i] > tab[i+1]){
        aTrier = 1;
        temp = tab[i];
        tab[i] = tab[i+1];
        tab[i+1] = temp;
      }
    }
  }
  return;
}

int partionner(int tab[],int p,int r);

void triRapide(int tab[],int p,int r){
  /* Première version du tri rapide */
  if (p < r){
    int q = partionner(tab,p,r);
    triRapide(tab,p,q);
    triRapide(tab,q+1,r);
  }
  return;
}

int partionner(int tab[],int p,int r){
  /* sépare le tableau en sous la forme [L,x,U]
  avec, x : élement pivot
        L : tableau contenant les élements inférieurs à x
        U : tableau contenant les éléments supérieurs à x
                                                        */
  int x = tab[p]; //élément pivot
  int i = p-1; //pour le parcours à partir de la gauche
  int j = r+1; //pour le parcours à partir de la gauche
  while (1) { //on boucle
    while(tab[--j] > x); //on cherche le premier j pour lequel tab[j] ≤ x
    while(tab[++i] < x); //on cherche le premier i pour lequel tab[i] ≥ x
    if (i < j){ //si i et j ne se sont pas croisés alors on les échanges leurs valeurs
      int temp = tab[i];
      tab[i] = tab[j];
      tab[j] = temp;
    }
    else //sinon c'est qu'on a fini de partionner
      return j; //on retourne j indice de l'élément juste avant x dans le tableau
  }
}

int part(int tab[],int p,int r);

void quickSort(int tab[],int p,int r){
  /* Seconde version du tri rapide */
  if (p < r){
    int q = partionner(tab,p,r);
    quickSort(tab,p,q-1);
    quickSort(tab,q+1,r);
  }
  return;
}

int part(int tab[],int p,int r){
  /* sépare le tableau en sous la forme [L,x,U]
  avec, x : élement pivot
        L : tableau contenant les élements inférieurs à x
        U : tableau contenant les éléments supérieurs strictement à x
                                                        */
  int x = tab[r]; //élément pivot
  int i = p-1; //élément en fin des éléments inférieurs à x (invariant)
  int j; //indice pour le parcours
  for(j=p; j < r ; j ++){
    if (tab[j] <= x){
      int temp = tab[++i];
      tab[i] = tab[j];
      tab[j] = temp;
    }
  }
  return i;
}


int main(int argc, char const *argv[]) {
  int tab[MAX]={4,5,6,3,4,7,1};
  int t = 7;
  triRapide(tab,0,t-1);
  afficherTab(t,tab);
  return 0;
}
