#include <stdio.h>


int main() {

  printf("Veuillez rentrer un caractère...\n");
  
  switch(getchar()) {
    case 'n':
    case 'N':
    case 'f':
    case 'F':
    case '1':
    case '6':
    case ' ':
    case 'a':
    case 'A':
    case 'u'://je n'écris pas les autres
      printf("C'est un bon caractère\n");
      break;
      // Pas de default nécessaire ici
  }


  return 0;
}
