#include <stdio.h>

struct point {
    int x;
    int y;
};

int main() {

    struct point p1 = {4, 5};
    printf("Les coordonnées de p1 sont (%d, %d)\n", p1.x, p1.y);
    p1.x = 40;
    p1.y = -10;
    printf("Les coordonnées de p1 sont (%d, %d)\n", p1.x, p1.y);

    struct point * pnt = &p1; // pointeur sur struct point
    (*pnt).x = 123;
    pnt->y = -30; // équivalent ) (*p1).y, on utilise cette syntaxe plus compacte

    printf("Les coordonnées pointées par pnt sont (%d, %d)\n", pnt->x, pnt->y);
    printf("Les coordonnées de p1 sont (%d, %d)\n", p1.x, p1.y);
    return 0;
}
