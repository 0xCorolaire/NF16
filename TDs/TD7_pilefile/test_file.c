#include <stdio.h>

#include "file.h"

int main() {

   file f = creerFile();
   enfiler(&f, 1);
   enfiler(&f, 4);
   enfiler(&f, 6);
   printf("%d\n", defiler(&f));
   printf("%d\n", defiler(&f));
   printf("%d\n", defiler(&f));

    return 0;
}


