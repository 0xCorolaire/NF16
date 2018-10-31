#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 20
#define STRING_SIZE 60

struct menu {
    char tab[TAB_SIZE][STRING_SIZE];
    int n;
};

int max_length(struct menu m) {
    int max = strlen(m.tab[0]);
    int i;
    for(i=0; i<m.n; i++) {
        if(strlen(m.tab[i]) > max) {
            max = strlen(m.tab[i]);
        }
    }
    return max;
}

int affiche(struct menu m) {
    int l = max_length(m);
    int i,j;
    char choice[STRING_SIZE];
    do {

      system("clear");
      for(i=0; i<m.n; i++) {
        for(j=0; j< (l-strlen(m.tab[i]))/2; j++) {
	        printf(" ");
	}
	printf("%d : %s\n", i+1, m.tab[i]);
      }
      printf("\n\nVeuillez saisir un nom de menu (q pour quitter)\n");
      //fgets(choice, STRING_SIZE, stdin);
      gets(choice);
      // Comparer aux chaines
      for(i=0; i<m.n; i++) {
        if(strcmp(m.tab[i], choice) == 0) {
	  return i+1;
        }
      }

    } while(strcmp(choice, "q") != 0);
    return 0;
}


int main() {

    struct menu m;
    m.n = 3;
    strcpy(m.tab[0], "Poulet au curry");
    strcpy(m.tab[1], "Tajine d'agneau aux pruneaux");
    strcpy(m.tab[2], "Lapin à la moutarde");

    int resultat = affiche(m);
    printf("Le résultat est %d\n", resultat);

    return 0;
}
