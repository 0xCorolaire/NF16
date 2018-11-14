#include "tp3.h"

//typedef struct Note T_Note;
//typedef T_Note* T_ListeNotes;

 T_Note* creerNote(float note, char *matiere){
    if(note>=0 && note<=20){
        T_Note* nouveau = (T_Note*)malloc(sizeof(T_Note));
        nouveau->note = note;
        nouveau->matiere = matiere;
        nouveau->suivant = NULL;
        return nouveau;
    }
}

T_ListeEtu creerListe(){
    T_ListeEtu l = (T_ListeEtu)(malloc(sizeof(T_Etudiant)));
    l->identifiant = -1; //on suppose que les identifiants sont des entiers naturels
                        // et on se sert de -1 pour identifier une liste vide
}

T_Etudiant *creerEtudiant(int idEtu, char *nom, char *prenom){
    T_Etudiant* e = (T_Etudiant*)(malloc(sizeof(T_Etudiant)));
    e->identifiant = idEtu;
    e->nom = nom;
    e->prenom = prenom;
    e->nbrNotes = 0;
    e->moyenne = -1;
    e->liste = e->suivant = NULL;

}

T_ListeNotes ajouterNote(float note, char *matiere, T_ListeNotes listeNotes){
     T_Note* nouveau = creerNote(note, matiere);
     if(listeNotes)
        nouveau->suivant = listeNotes;
     else{
        nouveau = (T_ListeNotes)(malloc(sizeof(T_Note)));
        nouveau->note = note;
        nouveau->matiere = matiere;
        nouveau->suivant = NULL;
     }
     return nouveau;
 }

  T_ListeEtu ajouterNoteEtu(float note, char *matiere, int idEtu, T_ListeEtu listeEtu){
     while(listeEtu && listeEtu->identifiant != idEtu){
         listeEtu = listeEtu->suivant;
     }
     if(listeEtu){
        listeEtu->liste = ajouterNote(note,matiere,listeEtu->liste);
        listeEtu->nbrNotes++;
        return listeEtu;
     }
     else{ //l'étudiant n'existe pas dans la liste
        T_Etudiant* e = creerEtudiant(idEtu, "INDEFINI", "INDEFINI");
        e->liste = ajouterNote(note,matiere,e->liste);
        e->suivant=listeEtu;
        e->nbrNotes=1;
        return e;
     }
 }


 T_ListeEtu supprimerNoteEtu(char *matiere, int idEtu, T_ListeEtu listeEtu){
    T_ListeEtu etuActuel = listeEtu;
    while(etuActuel->identifiant!=idEtu){
        etuActuel = etuActuel->suivant;
    }
    if(etuActuel){
        T_ListeNotes actuel = etuActuel->liste;
        if(!(strcmp(actuel->matiere,matiere))){
            etuActuel->liste = etuActuel->liste->suivant; //cas particulier o le 1er lment est  supprimer
            etuActuel->nbrNotes--;
        }
        else{
            while(actuel->suivant && !(strcmp(actuel->suivant->matiere,matiere))){
                actuel = actuel->suivant;
            }
            // la fin du while, on se retrouve  l'adresse de la note juste avant celle recherche
            // ou  l'adresse de la dernire note
            if(!(strcmp(actuel->matiere,matiere))){
                T_Note* tmp = actuel->suivant;
                if(actuel->suivant)
                    actuel->suivant = actuel->suivant->suivant;
                free(tmp);
            }
        }
    }
    return listeEtu;
 }

T_ListeEtu ajouterEtu(int idEtu, char *nom, char *prenom, T_ListeEtu listeEtu){
    T_Etudiant* e = creerEtudiant(idEtu, nom, prenom);
    //on ajoute le nouvel tudiant  la tte de la liste
    if(listeEtu->identifiant != -1) e->suivant = listeEtu; //traitement du cas o la liste est initialise
    return e; //si elle est initialise, on met la liste  la suite de e et on renvoie e
             // si la liste tait vide, alors e sera son premier lment
 }


 void afficherListeEtu(T_ListeEtu listeEtu){
    if(listeEtu->identifiant==-1) printf(" La liste est actuellement vide \n");
    else {
        while(listeEtu){
        printf("Nom: %s, prenom: %s, liste des notes: \n",listeEtu->nom, listeEtu->prenom);
        T_ListeNotes l = listeEtu->liste;
        while(l){
            printf("Matiere: %s \t Note obtenue: %d \n",l->matiere, l->note);
            l = l->suivant;
        }
        if(listeEtu->moyenne>0) printf("Pour une moyenne de %.2f \n",listeEtu->moyenne);
        listeEtu = listeEtu->suivant;
    }
    }
 }

float calculMoyenneEtu(T_Etudiant* etu){
    int i;
    float somme=0;
    T_ListeNotes noteActuelle = etu->liste;
    for(i=0;i<etu->nbrNotes;i++){
        somme += noteActuelle->note;
        noteActuelle = noteActuelle->suivant;
    }
    return somme/etu->nbrNotes;
}

void calculMoyenne(T_ListeEtu liste){
    while(liste){
        liste->moyenne = calculMoyenneEtu(liste);
        liste=liste->suivant;
    }
}


void trierListeEtu(T_ListeEtu liste){// ici on va ranger les elements dans l'ordre croisssant avant de les afficher.
   T_ListeEtu temp, temp1, temp3;
   float max;
   calculMoyenne(liste); //on s'assure que toutes les valeurs sont calcules
   for(temp=liste ; temp!=NULL ; temp=temp->suivant)
   {
     temp3=temp;
     max=temp->moyenne;
     for(temp1=temp->suivant ; temp1!=NULL ; temp1=temp1->suivant)
     {
        if(max < temp1->moyenne)
        {
           temp3=temp1; // le 3 temporaire est l'adresse de l'lement o se trouve le minimum
           max=temp3->moyenne;
        }
     }
     temp3->moyenne=temp->moyenne; //echange des 2 elements...
     temp->moyenne=max;
   }
}

void afficherClassement(T_ListeEtu listeEtu){
    trierListeEtu(listeEtu);
    printf("Classement des tudiants dans l'ordre dcroissant de leur moyenne: \n");
    while(listeEtu){
        printf("Nom: %s, prenom: %s, Moyenne: %.2f\n",listeEtu->nom, listeEtu->prenom, listeEtu->moyenne);
        listeEtu = listeEtu->suivant;
    }
}
