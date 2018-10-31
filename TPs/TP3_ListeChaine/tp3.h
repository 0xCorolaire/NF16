#include <stdio.h>
#include <stdlib.h>

  //Structure d'une note
  typedef struct Note {
    float note;
    char* matiere;
    struct Note* suivant;
  } T_Note;
  typedef struct T_Note* T_ListeNotes;

  //Structure d'un étudiant
  typedef struct Etudiant {
    int id;
    char* nom;
    char* prenom;
    T_ListeNotes* listeNotes;
    int nbNotes;
    float moyenne;
    struct Etudiant* suivant;
  } T_Etudiant;
  typedef struct T_Etudiant T_ListeEtus;

  //créer une note
  T_Note *creerNote(float note, char *matiere);

  //Créer un étudiant
  T_Etudiant *creerEtudiant(int idEtu, char *nom, char *prenom);

  //Ajout d'une note à la liste de note actuelle
  T_ListeNotes ajouterNote(float note, char *matiere, T_ListeNotes listeNotes);
