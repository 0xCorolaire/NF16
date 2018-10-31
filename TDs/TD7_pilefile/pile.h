#define MAXP 100

/*Implantation par tableau
• Convention :
– sommet[P] pointe sur le dernier élément ajouté et
vaut 0 initialement
– Longueur [P] (= MAXP) donne la taille maximale
de la pile
• Algorithmes :
– Créer_pile, Pile_vide, Pile_pleine, Empiler et
Dépiler
– Insérer (non abordé)
*/

// On peut représenter une pile à l'aide d'une structure contenant deux attributs :
// Un tableau dans lequel les éléments seront empilés
// Un indice pour savoir combien d'éléments sont actuellement empilés
typedef struct pile {
    int sommet; // Indice de l'élement au sommet de la pile
    int tab[MAXP];
} pile;

pile creerPile();
int pileVide(pile * p);
int pilePleine(pile * p);
int empiler(pile * p, int val);
int depiler(pile * p);
void afficherPile(pile p);
