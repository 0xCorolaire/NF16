#include <stdio.h>

int main() {

    char i;
    for(i=31; i<127; i++) {
        printf("Le code ASCII %d correspond au caractère %c\n", i, i);
    }


    return 0;
}
