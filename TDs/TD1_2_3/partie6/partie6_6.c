#include <stdio.h>

int main() {

    int i,n,s;

    printf("Veuillez saisir un entier....\n");
    scanf("%d", &n);

    s = 1;
    for(i=2; i<=n;i++) {
        s+=7;
    }
    printf("s(%d) = %d\n", i, s);


    return 0;
}
