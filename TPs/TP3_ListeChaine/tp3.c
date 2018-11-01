#include <stdio.h>
#include <stdlib.h>
#include "tp3.h"

/* Nom: NF16 - TP03
 * Sujet: Listes chaînées.
 * Auteurs: PAIGNEAU Hugo & LAMNDASNI Ayman
 * Section: GI02
 */

//Créaation d'une note
T_Note *creerNote(float note, char *matiere){
  //On vérifie que la note est bien comprise entre 0 et 20
  if(note>=0 && note<=20){
    T_Note* newNote = NULL;
    newNote = malloc(sizeof(T_Note));
    // On vérifie que l'allocation s'est bien passé
    if(newNote != NULL){
      newNote->note = note;
      strcpy(newNote->matiere,matiere);
      newNote->suivant = NULL;
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
  T_Etudiant* newEtudiant = NULL;
  newEtudiant = malloc(sizeof(T_Etudiant));
  if(newEtudiant != NULL){
    T_listeNotes* liste = NULL;
    newEtudiant->id = idEtu;
    strcpy(newEtudiant->nom,nom);
    strcpy(newEtudiant->prenom,prenom);
    newEtudiant->listeNotes = liste;
    newEtudiant->nbNotes = 0;
    newEtudiant->moyenne = 0;
    newEtudiant->suivant = NULL;
    return newEtudiant;
  }else{
    printf("Error malloc");
    return NULL;
  }
};

//Ajout d'une note à la liste de note actuelle
T_ListeNotes ajouterNote(float note, char *matiere, T_ListeNotes listeNotes){
  T_Note* newN = NULL;
  newN = creerNote(note,matiere);
  if(listeNotes!=NULL){
    newN->suiv=listeNotes;
    return newN;
  }else{
    printf("Error malloc");
    return NULL;
  }
};
