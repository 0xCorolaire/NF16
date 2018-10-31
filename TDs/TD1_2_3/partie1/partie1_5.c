#include <stdio.h> // Contient la déclaration de printf/scanf
// Chaque fonction doit être déclarée avant d'être utilisée

int main() {
    int x, y, buffer;
    printf("Veuillez saisir deux nombres entiers\n");
    scanf("%d %d", &x, &y);

    buffer = x;
    x = y;
    y = buffer;
    printf("x vaut %d et y vaut %d\n", x, y);

    return 0;
}
