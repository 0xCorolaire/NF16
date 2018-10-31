#include <stdio.h>

int main() {

    int i,n,result;

    printf("Veuillez saisir un entier....\n");
    scanf("%d", &n);

    result = 1;
    for(i=2; i<=n;i++) {
        result*=i; // result = result*i;
    }

    printf("%d! = %d\n", n, result);


    return 0;
}
