#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
	int cle;
	struct cellule * pred;
	struct cellule * succ;
} cellule;

typedef cellule * listeDoubleChaine;
/* on utilise cellule * pour passer des cellules parfois, mais c'est
	sémantiquement différent */

listeDoubleChaine ajouterTete(listeDoubleChaine liste, cellule y){
	cellule * x = (cellule *)malloc(sizeof(cellule));
	*x = y;
	x->succ = liste;
	x->pred = NULL;
	if (liste != NULL) // si liste n'est pas vide
		liste->pred = x;
	liste = x;
	return liste;
}

listeDoubleChaine supprimer(listeDoubleChaine liste, cellule * x) {
	if (x == liste)
		liste = x->succ;
	else
		x->pred->succ = x->succ;
	x->succ = NULL;

	return liste;
}

void afficher(listeDoubleChaine liste) {
	cellule * y = liste;
	printf("Affichage de la liste en avant \n");
	printf("NULL -> ");
	while (y->succ != NULL) {
		printf("%d -> ",y->cle);
		y = y->succ;
	}
	printf("%d -> NULL\n",y->cle);

	printf("Affichage de la liste en arrière \n");
	printf("NULL -> ");
	while (y->pred != NULL) {
		printf("%d -> ",y->cle);
		y = y->pred;
	}
	printf("%d -> NULL\n",y->cle);
	return;
}


cellule * rechercher(listeDoubleChaine liste, int k) {
	cellule * y = liste;
	while (y != NULL && y->cle != k) {
		y = y->succ;
	}

	return y;
}

int main(int argc, char const *argv[]) {
	listeDoubleChaine maListe = (listeDoubleChaine)malloc(sizeof(cellule));
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
	return 0;
}
