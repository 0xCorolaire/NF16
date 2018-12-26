#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define PRINCIPALE "-----------\nPrincipale : \n"
#define TEMPORAIRE "\nTemporaire : \n"

typedef struct lifo {
	int tab[MAX]; //le tableeau pour stocker
	int sommet; //entier qui indique le sommet
} lifo;


lifo creerPile(){
	lifo pile;
	pile.sommet = -1; //on initialise juste le sommet
	return pile;
}

int pilePleine(lifo p){
	return (p.sommet == MAX-1);
}

int pileVide(lifo p){
	return (p.sommet == -1);
	/*on choisit -1 plutôt que 0 car cela permet de stocker
	un élément de plus */

}

void empiler(lifo * pile, int elem){
	/* empile l'élément x sur pile,
	on utilise un pointeur pour modifier dynamiquement pile*/
	if (pilePleine(*pile)){
		printf("Pile pleine ! \n");
		return;
	}
	//on incrémente le sommet puis on ajoute l'élément
	pile->tab[++(pile->sommet)] = elem;
	return;
}

int depiler(lifo *pile){
	/* retourne l'élément en sommet de pile, -42 si la pile est vide
	on utilise un pointeur pour modifier dynamiquement pile */
	if (pileVide(*pile)){
		printf("Pile vide ! \n");
		return -42; //renvoyer une valeur non probante ici
	}
	//on renvoie l'élement et on décrémente le sommet
	return pile->tab[(pile->sommet)--];
}

void inserer(lifo *p, int x){
	/* insère dynamiquement un entier x dans un liste p
	on utilise un pointeur pour modifier dynamiquement pile */
	if (pileVide(*p) || x <= p->tab[p->sommet])
	//si la liste est vide ou si le x est inférieur à l'élément au sommet
		empiler(p,x); //on l'empile
	else{
		int y = depiler(p); //sinon on garde de côté l'élement en sommet
		inserer(p,x); //on essaye d'insérer
		empiler(p,y); //une fois l'insertion faite on empile l'élement précédent
	}
	return;
}

void afficherLifo(lifo p){
	/* affiche une liste p */
	if (!pileVide(p)){//si la liste n'est pas vide
		printf("|| %4d ||\n",depiler(&p)); // on affiche l'élément en sommet
		//ici on modifie la liste p qui est une variable local à la fonction
		//pas de déstruction globale donc
		afficherLifo(p); //on affiche le reste
	}
	else // si la liste est vide
		printf("==========\n"); //on affiche juste le fond
	return;
}

void insererIter(lifo * p,int x) {
	/* Procédure itérative : on stocke les éléments temporaires
		dans une autre pile appelée temp */
	lifo temp = creerPile(); //initialisation
	printf("#Dépilage de la principale :\n");
	while (!pileVide(*p) && p->tab[p->sommet] < x) {
		empiler(&temp,depiler(p));//on empile dans temps ce que l'on dépile dans p
		printf(PRINCIPALE);
		afficherLifo(*p);
		printf(TEMPORAIRE);
		afficherLifo(temp);
	}
	printf("\n#Ajout de x= %d :\n",x);
	empiler(p,x); //on empile x dans p
	printf(PRINCIPALE);
	afficherLifo(*p);
	printf(TEMPORAIRE);
	afficherLifo(temp);
	printf("\n#Ré-empilage de la principale :\n");
	while (!pileVide(temp)) {
		empiler(p,depiler(&temp)); //on empile dans p ce que l'on dépile dans temp
		printf(PRINCIPALE);
		afficherLifo(*p);
		printf(TEMPORAIRE);
		afficherLifo(temp);
	}
	printf("\n\n");
	return;
}

int main(int argc, char const *argv[]) {
	lifo maPile = creerPile();
	int i;
	empiler(&maPile,3);
	inserer(&maPile,10);
	inserer(&maPile,2);
	inserer(&maPile,6);
	inserer(&maPile,7);
	printf("# Sommet : %d\n",maPile.sommet);
	afficherLifo(maPile);
	insererIter(&maPile,4);
	printf("# Sommet : %d\n",maPile.sommet);
	return 0;
}
