#include <stdio.h>
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

int main() {

    struct menu m;
    int i;
    printf("Combien de plats ?\n");
    scanf("%d", &m.n);
    for(i=0; i<m.n; i++) {
        scanf("%s", &m.tab[i]);
    }

    printf("Liste des menus :\n");
    for(i=0; i<m.n; i++) {
        printf("%d - %s\n", i, m.tab[i]);
    }
    printf("Le plus long fait %d caractères\n", max_length(m));


    return 0;
}
