#include <stdio.h>

int main() {

    char i;
    for(i='a'; i<'z'; i++) {
        printf("caractère %c, décimal : %d, hexa : %d\n", i, i, i);
    }
    for(i='A'; i<'Z'; i++) {
        printf("caractère %c, décimal : %d, hexa : %d\n", i, i, i);
    }

    return 0;
}
