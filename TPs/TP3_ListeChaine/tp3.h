#ifndef TD3_H_INCLUDED
#define TD3_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

struct Note
{
    int note;
    char* matiere;
    struct Note* suivant;
};

typedef struct Note T_Note;
typedef T_Note* T_ListeNotes;

struct Etudiant
{
    int identifiant;
    char* nom;
    char* prenom;
    T_ListeNotes liste;
    int nbrNotes;
    float moyenne;
    struct Etudiant* suivant;
};

typedef struct Etudiant T_Etudiant;
typedef T_Etudiant * T_ListeEtu;

T_Note* creerNote(float note, char *matiere); //Création d’un élément d’une liste de notes :
T_Etudiant *creerEtudiant(int idEtu, char *nom, char *prenom); //Création d’un élément d’une liste d’étudiants :

T_ListeNotes ajouterNote(float note, char *matiere, T_ListeNotes listeNotes); //Ajout d’une note en tête d’une liste de notes (renvoie la liste de notes modifiée)
T_ListeEtu ajouterNoteEtu(float note, char *matiere, int idEtu, T_ListeEtu listeEtu); //Ajout d’une note pour un étudiant dans une liste d’étudiants
//Cette fonction renvoie la liste d’étudiants modifiée. On veillera à bien gérer le cas de l’ajout d’un étudiant
// dans la liste si celui-ci n’y figure pas encore.

T_ListeEtu supprimerNoteEtu(char *matiere, int idEtu, T_ListeEtu listeEtu); //Suppression d’une note pour un étudiant dans une liste d’étudiants :
// Cette fonction renvoie la liste d’étudiants modifiée. On veillera à retirer l’étudiant de la liste si celui-ci n’a
// plus aucune note.

void afficherListeEtu(T_ListeEtu listeEtu); //6. Affichage d’une liste d’étudiants (nom, prénom, liste des notes)

void afficherClassement(T_ListeEtu listeEtu); //7. Affichage du classement des étudiants par ordre décroissant de la moyenne (nom, prénom, moyenne) :

T_ListeEtu ajouterEtu(int idEtu, char *nom, char *prenom, T_ListeEtu listeEtu);
T_ListeEtu creerListe();
void calculMoyenne(T_ListeEtu);
void trierListeEtu(T_ListeEtu);


#endif // TD3_H_INCLUDED
