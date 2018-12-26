#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define PRINCIPALE "-----------\nPrincipale : \n"
#define TEMPORAIRE "\nTemporaire : \n"

typedef struct fifo {
	int tab[MAX]; //le tableeau pour stocker
	int longueur;
	int tete;
	int queue;
} fifo;


fifo creerFile(){
	fifo file;
	file.longueur = MAX; // la file peut comporter au plus longueur - 1 éléments
	file.tete = 0; //liste vide au début
	file.queue = 0; //liste vide au début
	return file;
}

int filePleine(fifo f){
	return (((f.queue +1)%f.longueur) == f.tete);
}

int fileVide(fifo f){
	return (f.queue == f.tete);
}

void enfiler(fifo * f, int x){
	/* enfile l'élément x sur f,
	on utilise un pointeur pour modifier dynamiquement f */
	if (filePleine(*f)){
		printf("File pleine ! \n");
		return;
	}
	f->tab[f->queue] = x;
	if (f->queue == f->longueur - 1)
		f->queue = 0;
	else
		(f->queue)++;
	return;
}

int defiler(fifo * f){
	/* retourne l'élément en tete de file, -42 si la file est vide
	on utilise un pointeur pour modifier dynamiquement f */
	if (fileVide(*f)){
		printf("File vide ! \n");
		return -42; //renvoyer une valeur non probante ici
	}
	int x = f->tab[f->tete];
	if (f->tete == f->longueur - 1)
		f->tete = 0;
	else
		(f->tete)++;
	return x;
}

void afficherFifo(fifo f){
	/* affiche la file f */

	if(fileVide(f)){
		printf("File vide !\n");
		return;
	}
	int l; //nombre d'éléments dans la file
	if(f.tete > f.queue)
		l = (f.longueur - f.tete) + f.queue;
	else
		l = f.queue - f.tete;
	int i;
	printf("	");
	for(i=0;i<l;i++)
		printf("====");
	printf("\nT ");
	while (!fileVide(f)) {
		printf("%3d,",defiler(&f));
	}
	printf(" Q\n	");
	for(i=0;i<l;i++)
		printf("====");
	printf("\n");
	printf("\n");
	return;
}


int main(int argc, char const *argv[]) {
	fifo maFile = creerFile();
	int i;
	int m = 20;
	for (i = 1; i <15; i++){
		enfiler(&maFile,i);
		afficherFifo(maFile);
	}
	printf("# Tete : %d ; queue : %d \n",maFile.tete, maFile.queue);
	for (i = 0; i <m; i++){
		defiler(&maFile);
		afficherFifo(maFile);
	}
	printf("# Tete : %d ; queue : %d\n",maFile.tete, maFile.queue);
	for (i = 0; i <m; i++){
		enfiler(&maFile,i);
		afficherFifo(maFile);
	}
	printf("# Tete : %d ; queue : %d \n",maFile.tete, maFile.queue);
	for (i = 0; i <m; i++){
		defiler(&maFile);
		afficherFifo(maFile);
	}
	printf("# Tete : %d ; queue : %d\n",maFile.tete, maFile.queue);
	return 0;
}
