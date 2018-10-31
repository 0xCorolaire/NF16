#include <stdio.h>

#define CURRENT_YEAR 2017

int main() {

  int bornYear, age;
  printf("Veuiller donner votre année de naissance...\n");

  scanf("%d", &bornYear);

  age = CURRENT_YEAR - bornYear;  
  if(age >= 0 && age <= 130) {
    if(age <= 50) {
      printf("Pour l'instant, ça va\n");
    } else {
      printf("Vous êtes sur la mauvaise pente\n");
    }
  } else {
    printf("L'age renseigné n'est pas valide...\n");
  }


  return 0;
}
