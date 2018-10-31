#include <stdio.h>

int main() {

    int a,b,c;
    c = 7;
    c++;
    a=c;
    c++;
    c--;
    b=c;
    b--;
    a=b;
    printf("a vaut %d, b vaut %d, c vaut %d\n", a, b, c);

    return 0;

}
