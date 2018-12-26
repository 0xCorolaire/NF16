#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
	int cle;
	struct cellule * succ;
} cellule;

typedef cellule * listeChaine;
/* on utilise cellule * pour passer des cellules parfois, mais c'est
	sémantiquement différent */

listeChaine ajouterTete(listeChaine liste, cellule y){
	cellule * x = (cellule *)malloc(sizeof(cellule));
	*x = y;
	x->succ = liste;
	liste = x;
	return liste;
}

void deleteList(listeChaine l) {
	cellule * temp;
	while (l != NULL) {
		temp = l;
		l = l->succ;
		free(temp);
	}
	return;
}

listeChaine supprimer(listeChaine liste, cellule * x) {
	if (x == liste)
		liste = x->succ;
	x->succ = NULL;
	return liste;
}

void afficher(listeChaine liste) {
	cellule * y = liste;
	printf("Affichage de la liste en avant \n");
	printf("NULL -> ");
	while (y->succ != NULL) {
		printf("%d -> ",y->cle);
		y = y->succ;
	}
	printf("%d -> NULL\n",y->cle);

	return;
}


cellule * rechercher(listeChaine liste, int k) {
	cellule * y = liste;
	while (y != NULL && y->cle != k) {
		y = y->succ;
	}

	return y;
}

int main(int argc, char const *argv[]) {
	listeChaine maListe = (listeChaine)malloc(sizeof(cellule));
	maListe->cle = 23;
	cellule x1,x2,x3;
	x1.cle = 13;
	x2.cle = 21;
	x3.cle = 14;
	maListe = ajouterTete(maListe,x1);
	maListe = ajouterTete(maListe,x2);
	maListe = ajouterTete(maListe,x3);
	afficher(maListe);
	printf("\n");
	maListe = supprimer(maListe,maListe);
	afficher(maListe);
	printf("\n");
	cellule * xr = rechercher(maListe,13);
	afficher(xr);
	printf("\n");
	afficher(maListe);
	deleteList(maListe);
	afficher(maListe);
	return 0;
}
