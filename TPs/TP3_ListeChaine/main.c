#include <stdio.h>
#include <stdlib.h>
#include "tp3.h"

int main() {
  char m[30] = "Maths";
  T_ListeNotes* listeNote = NULL;
  T_Note* n =malloc(sizeof(n));
  n = creerNote(10.5,m);

  return 0;
}
