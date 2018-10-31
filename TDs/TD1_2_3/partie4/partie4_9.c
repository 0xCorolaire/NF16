#include <stdio.h>


int main() {

  int var;

  printf("Veuillez rentrer un entier...\n");
  scanf("%d", &var);

  if(var == 0) {
    printf("L'entier renseigné vaut zéro\n");
  } else if(var%2 == 0) {
    printf("L'entier %d est pair\n", var);
  } else {
    printf("L'entier %d est impair\n", var);
  }

  return 0;
}
