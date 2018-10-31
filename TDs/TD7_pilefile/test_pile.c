#include <stdio.h>

#include "pile.h"

int main() {

    pile p = creerPile();
    empiler(&p, 1);
    empiler(&p, 3);
    empiler(&p, 5);
    afficherPile(p);
    printf("On dépile %d\n", depiler(&p));
    afficherPile(p);

    return 0;
}
