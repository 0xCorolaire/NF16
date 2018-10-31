#define MAXF 100

// Implantation par tableau en file tournante
/*Conventions :
– Tête[F] pointe sur le premier élément à défiler
– Queue[F] pointe sur le premier emplacement libre
– Initialement Tête[F]=Queue[F]=0
– Longueur[F] retourne la taille maximale de F
– On dit que la File est vide si Tête[F]=Queue[F]
– On dit que la File est pleine si
Tête[F]=modulo(Queue[F]+1, longueur[F])//
*/
typedef struct file {
    int tab[MAXF];
    int tete; // Premier element à défiler
    int queue; // Premier emplacement libre
} file;

file creerFile();
int fileVide(file * f);
int filePleine(file * f);
int enfiler(file * f, int val);
int defiler(file * f);
void afficherFile(file f);
