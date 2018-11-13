#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"

int main() {
  printf("/*-------------------------------*/\n");
	printf("/*---------*/NF16 TP3/*----------*/\n");
	printf("/*-------------------------------*/\n");
	printf("/*----------*/Menu/*-------------*/\n");
	printf("/*-------------------------------*/\n");
  T_ListeEtu listeEtu = creerListe();
  int isSelected = 0;
  while(1){
    isSelected = 0; //on remet la variable à 0 pour ne pas revenir directemenet au même choix à la nouvelle itération du while
    printf("Bienvenue dans le management des étudiants. Veuillez choisir une option : \n\n");
		printf("1. Ajouter un étudiant à la liste\n\n");
		printf("2. Ajouter une note a un étudiant\n\n");
		printf("3. Supprimer une note\n\n");
		printf("4. Afficher la liste des étudiants\n\n");
		printf("5. Afficher le classement des étudiants\n\n");
		printf("6. Quitter \n\n");
    while(isSelected==0){
		    scanf("%d", &isSelected);
    }
    switch(isSelected){
      case 1: {
        printf("Ajout d'un étudiant choisi\n");
        int Selection = 1;
        while(Selection){
          int id_etu;
          char* nom = (char*) malloc(25*sizeof(char));
          char* prenom = (char*) malloc(25*sizeof(char));
          printf("Saisissez l'id, le nom et le prenom de l'etudiant :\n");
          scanf("%d %s %s", &id_etu, nom, prenom);
          listeEtu = ajouterEtu(id_etu, nom, prenom, listeEtu);
          printf("Tapez 0 pour arrêter, ou un autre chiffre pour continuer.\n");
          scanf("%d", &Selection);
        }
        break;
      }

      case 2: {
        //Ajouter peut être un test pour voir si les entrées sont valides ???
        printf("Ajout de note choisi\n");
        float note;
  			char* matiere = (char*) malloc(6*sizeof(char));
  			int id;
  			afficherListeEtu(listeEtu);
  			printf("Saisissez l'id de l'étudiant :\n");
  			scanf("%d", &id);
  			printf("Saisissez la matière\n");
  			scanf("%s", matiere);
  			printf("Saissez la note\n");
  			scanf("%f", &note);
  			listeEtu = ajouterNoteEtu(note, matiere, id, listeEtu);
  			free(matiere);
  			break;
      }

      case 3: {
        printf("Suppression de note choisie\n");
        int id = 0;
  			char* matiere = (char*) malloc(6*sizeof(char));
  			afficherListeEtu(listeEtu);
  			printf("Saisissez l'id de l'étudiant puis la note que vous voulez supprimer ( en entrant la matiere )'\n");
  			scanf("%d", &id);
  			scanf("%s", matiere);
  			listeEtu = supprimerNoteEtu(matiere, id, listeEtu);
  			break;
      }

      case 4: {
        printf("Vous voulez afficher la liste des étudiants : \n");
        afficherListeEtu(listeEtu);
        break;
      }

      case 5: {
        printf("Vous choisissez d'afficher le classement : \n");
        afficherClassement(listeEtu);
        break;
      }
    default:
      break;
    }
  }
  printf("FIn du prograaaaaamme");


  return 0;
}
