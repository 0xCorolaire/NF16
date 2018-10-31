#include <stdio.h>

/*int my_strlen(char chaine[]) {
    int i = 0; // ou initaliser à 1 si on veut comptabilitser '\0'
    while(chaine[i] != '\0') {
        i++;
    }
    return i;
}*/

int my_strlen(char * pt) {
    int i=0;
    while(*(pt+i) != '\0') {
        i++;
    }
    return i;
}


int main() {

    char bjr[] = "Bonjour";
    printf("%s est de longueur %d\n", bjr, my_strlen(bjr));


    return 0;
}

