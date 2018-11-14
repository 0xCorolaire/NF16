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

T_Note* creerNote(float note, char *matiere); //Cr�ation d�un �l�ment d�une liste de notes :
T_Etudiant *creerEtudiant(int idEtu, char *nom, char *prenom); //Cr�ation d�un �l�ment d�une liste d��tudiants :

T_ListeNotes ajouterNote(float note, char *matiere, T_ListeNotes listeNotes); //Ajout d�une note en t�te d�une liste de notes (renvoie la liste de notes modifi�e)
T_ListeEtu ajouterNoteEtu(float note, char *matiere, int idEtu, T_ListeEtu listeEtu); //Ajout d�une note pour un �tudiant dans une liste d��tudiants
//Cette fonction renvoie la liste d��tudiants modifi�e. On veillera � bien g�rer le cas de l�ajout d�un �tudiant
// dans la liste si celui-ci n�y figure pas encore.

T_ListeEtu supprimerNoteEtu(char *matiere, int idEtu, T_ListeEtu listeEtu); //Suppression d�une note pour un �tudiant dans une liste d��tudiants :
// Cette fonction renvoie la liste d��tudiants modifi�e. On veillera � retirer l��tudiant de la liste si celui-ci n�a
// plus aucune note.

void afficherListeEtu(T_ListeEtu listeEtu); //6. Affichage d�une liste d��tudiants (nom, pr�nom, liste des notes)

void afficherClassement(T_ListeEtu listeEtu); //7. Affichage du classement des �tudiants par ordre d�croissant de la moyenne (nom, pr�nom, moyenne) :

T_ListeEtu ajouterEtu(int idEtu, char *nom, char *prenom, T_ListeEtu listeEtu);
T_ListeEtu creerListe();
void calculMoyenne(T_ListeEtu);
void trierListeEtu(T_ListeEtu);


#endif // TD3_H_INCLUDED
