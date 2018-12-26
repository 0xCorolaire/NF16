#include <stdio.h>
#include <stdlib.h>
#define MAX 20

//Définition de la structure d'arbre binaire
typedef struct tree {
	int key;
	struct tree * lTree;
	struct tree * rTree;
} tree;

typedef tree * bTree;

void initBTree(bTree* myTree,int k) {
	//Initialisation de la structure d'arbre binaire
	(*myTree) = (bTree)malloc(sizeof(tree));
	(*myTree)->key = k;
	(*myTree)->lTree = NULL;
	(*myTree)->rTree = NULL;
	return;
}

void parcoursPrefixe(bTree tree) {
	if (tree != NULL) {
		printf("%d ",tree->key);
		parcoursPrefixe(tree->lTree);
		parcoursPrefixe(tree->rTree);
	}
	return;
}

void parcoursInfixe(bTree tree) {
	if (tree != NULL) {
		parcoursInfixe(tree->lTree);
		printf("%d ",tree->key);
		parcoursInfixe(tree->rTree);
	}
	return;
}

void parcoursPostfixe(bTree tree) {
	if (tree != NULL) {
		parcoursPostfixe(tree->lTree);
		parcoursPostfixe(tree->rTree);
		printf("%d ",tree->key);
	}
	return;
}

bTree rechercheABR(bTree tree, int k) {
	//Fonction récursive de recherche
	if (tree == NULL || k == tree->key) //si l'arbre et null ou si on a trouvé
		return tree; //on retourne l'arbre
	if (k < tree->key)//sinon, selon la valeur du noeud actuel
		rechercheABR(tree->lTree,k); //on recherche à gauche
	else
		rechercheABR(tree->rTree,k); //ou on recherche à droite
}

bTree rechercheABRIter(bTree tree, int k) {
	//Fonction itérative de recherche
	while (tree != NULL && tree->key != k) //si l'arbre et null ou si on a trouvé
		if (k < tree->key)
			tree = tree->lTree; //on recherche à gauche
		else
			tree = tree->rTree; //on recherche à droite
	return tree; // on retourne l'arbre
}

bTree minABR(bTree tree) {
	while (tree->lTree != NULL) {//on descend le plus profond
		tree=tree->lTree;//à gauche
	}
	return tree;
}

bTree maxABR(bTree tree){
	while (tree->rTree != NULL) {//on descend le plus profond
		tree=tree->rTree;//à droite
	}
	return tree;
}

bTree father(bTree x,bTree tree) { //il peut exister une autre implémentation possible (cf. tableau des pères)
	//on part de la racine et on descend avec la clé jusqu'à trouver le père
	while (tree != NULL && tree->rTree != x && tree->lTree != x) {
		if (x->key < tree->key)
			tree = tree->lTree;
		else
			tree = tree->rTree;
	}
		return tree;
}

bTree successeurABR(bTree x, bTree tree) {
	if (x->rTree != NULL) //si le noeud admet un sous-arbre droit
		return minABR(x->rTree);//alors son successeur est le minimum de celui-ci
	//Dans l'autre cas, le successeur sera le premier noeud sur une branche différente
	bTree y = father(x,tree); //on récupère le père
	while (y != NULL && x == y->rTree) { //arrêt si le père est la racine ou s'il est sur une branche différente
		x = y;
		y = father(y,tree); //on prend le grand-père
	}
	return(y);
}

bTree predecesseurABR(bTree x, bTree tree) {
	if (x->lTree != NULL) //si le noeud admet un sous-arbre gauche
		return maxABR(x->rTree);//alors son prédecesseur est le maximum de celui-ci
	//Dans l'autre cas, le prédecesseur sera le premier noeud sur une branche différente
	bTree y = father(x,tree); //on récupère le père
	while (y != NULL && x == y->lTree) { //arrêt si le père est la racine ou s'il est sur une branche différente
		x = y;
		y = father(y,tree); //on prend le grand-père
	}
	return(y);
}

void insererABR(bTree * t, int k){
	bTree z;
	initBTree(&z,k);
	bTree y = NULL;
	bTree x = * t;
	while (x != NULL) {
		y = x;
		if (z->key < x->key)
			x = x->lTree;
		else
			x = x->rTree;
	}

	if (y == NULL)
		*t = z;
	else if (z->key < y->key)
		y->lTree = z;
	else
		y->rTree = z;
	return;
}

int main(int argc, char const *argv[]) {
	bTree myTree, myResult,maxTree;
	myTree = NULL;
	insererABR(&myTree,6);
				printf("onxhz\n");
		insererABR(&myTree,3);
			insererABR(&myTree,1);
			insererABR(&myTree,4);

	insererABR(&myTree,8);
		insererABR(&myTree,7);
		insererABR(&myTree,12);
		insererABR(&myTree,30);


	// initBTree(&myTree,6);
	// 	initBTree(&(myTree->lTree),3);
	// 		initBTree(&(myTree->lTree->lTree),1);
	// 		initBTree(&(myTree->lTree->rTree),4);
	//
	// 	initBTree(&(myTree->rTree),8);
	// 		initBTree(&(myTree->rTree->lTree),7);
	// 		initBTree(&(myTree->rTree->rTree),12);
	// 		initBTree(&(myTree->rTree->rTree->rTree),30);

	printf("\nParcours préfixe :\n");
	parcoursPrefixe(myTree);
	printf("\nParcours postfixe :\n");
	parcoursPostfixe(myTree);
	printf("\nParcours infixe :\n");
	parcoursInfixe(myTree);
	myResult = minABR(myTree);
	maxTree = maxABR(myTree);
	printf("\n");
	// while (myResult != maxTree) {
	// 	printf("Parcours rechercheABR : ");
	// 	myResult = rechercheABR(myTree,myResult->key);
	// 	printf("%d\n",myResult->key);
	//
	// 	printf("Son successeur : \t");
	// 	myResult = successeurABR(myResult,myTree);
	// 	printf("%d\n-------------\n",myResult->key );
	// }
	return 0;
}
