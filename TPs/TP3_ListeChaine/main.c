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

  int isSelected = 0;
  while(1){
    printf("Bienvenue dans le management des étudiants. Veuillez choisir une option : \n\n");
		printf("1. Ajouter un étudiant à la liste\n\n");
		printf("2. Ajouter une note a un étudiant\n\n");
		printf("3. Supprimer une note\n\n");
		printf("4. Afficher la liste des étudiants\n\n");
		printf("5. Afficher le classement des étudiants\n\n");
		printf("7. Quitter \n\n");
    while(isSelected==0){
		    scanf("%d", &isSelected);
    }
    switch(choix){

      case 1: {
        int Selection = 1;
        while(Selection){
          int id_etu;
          char* nom = (char*) malloc(25*sizeof(char));
          char* prenom = (char*) malloc(25*sizeof(char));
          printf("Saisissez l'id, le nom et le prenom de l'etudiant :\n");
          scanf("%s %s %d", &id_etu, nom, prenom);
          listeEtu = ajouterEtu(id_etu, nom, prenom, listeEtu);
          printf("Tapez 1 pour continuer, ou un autre chiffre pour faire autre chose.\n");
          scanf("%d", &Selection);
        }
        break;
      }

      case 2: {

        
      }



    default:
      break;
    }

  })



  return 0;
}
