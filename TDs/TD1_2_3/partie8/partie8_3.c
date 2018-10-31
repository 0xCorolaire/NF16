#include <stdio.h>

int my_isascii(char c) {
    int result;

    if(c >= 0 && c<= 127) {
        result = 1;    
    } else {
        result = 0;
    }
    return result;
}



int main() {

    char x;
    scanf("%c", &x);
    int result = my_isascii(x);
    printf("Result vaut %d\n", result);


    return 0;
}

