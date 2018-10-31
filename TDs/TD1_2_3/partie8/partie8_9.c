#include <stdio.h>

// int argc : indique le nombre d'arguments passés au programme
// char * argv[] : tableau de pointeurs vers char contenant les arguments
// - Le premier argument est toujours le nom du programme => argv[0]
int main(int argc, char * argv[]) {

	//printf("Il y a %d parametres\n", argc); // Pour afficher le nombre de paramètres
    //printf("%s\n", argv[0]); Pour afficher la commande exécutée pour lancer le programme

	// Il s'agit de l'opérateur préfixe de décrémentation
	// - argc est décrémenté de 1
	// - la valeur après décrémentation est comparée à 0
	// Tant qu'il reste des arguments non traités (en dehors du nom du programme) 
    while(--argc>0) {
		// Il s'agit de l'opérateur préfixe d'incrémentation
		// - argv est incrémenté de 1 (pointe alors vers l'adresse de la chaine de caractères suivante)
		// - L'opérateur * affiche ensuite la chaine de caractère se trouvant à cette adresse
		// On affiche l'argument suivant (en dehors du nom du programme)
        printf("%s\n", *++argv);
		printf("\n");
	}

    return 0;
}
