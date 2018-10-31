#include <stdio.h>
#include <stdlib.h>
#include "tp3.h"

//Créaation d'une note
T_Note *creerNote(float note, char *matiere){
  if(note>=0 && note<=20){
    T_Note* newNote;
    newNote = (T_Note*)malloc(sizeof(T_Note));
    if(newNote != NULL){
      newNote->note = note;
      newNote->matiere = matiere;
      newNote->suivant = NULL;
      printf("%d",newNote->note);
      return newNote;
    }else{
      printf("EROOR MALLOC");
      return NULL;
    }
  }else{
    printf("Note non comprise entre 0 et 20");
  }
};

//Création d'un étudiant
T_Etudiant *creerEtudiant(int idEtu, char *nom, char *prenom){
  T_Etudiant* newEtudiant;
  newEtudiant = (T_Etudiant*)malloc(sizeof(newEtudiant));
  if(newEtudiant != NULL){
    T_listeNotes* liste = NULL;
    newEtudiant->id = idEtu;
    newEtudiant->nom = nom;
    newEtudiant->prenom = prenom;
    newEtudiant->listeNotes = liste;
    newEtudiant->nbNotes = 0;
    newEtudiant->moyenne = 0;
    newEtudiant->suivant = NULL;
    return newEtudiant;
  }else{
    printf("Error malloc");
    return NULL;
  }
}

//Ajout d'une note à la liste de note actuelle
T_ListeNotes ajouterNote(float note, char *matiere, T_ListeNotes listeNotes){



}
