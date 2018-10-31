#include <stdio.h>
#define NMAX 6

int min(int * tab, int n);
int max(int * tab, int n);

int main() {

    int ex1[NMAX] = { 45, 75, 23, 149, 856, 130 };
    
    int minVal = min(ex1, NMAX);
    int maxVal = max(ex1, NMAX);

    printf("La plus petite valeur est %d\n", minVal);
    printf("La plus grande valeur est %d\n", maxVal);

    return 0;
}


int min(int * tab, int n) {
  
    int i, res;
    res = tab[0]; // res = *tab
    for(i=1;i<n;i++) {
        if(tab[i]<res) { // if(*(tab+i)<res) {
            res = tab[i]; // res = *(tab+i);
        }
    }
    return res;

}
int max(int * tab, int n) {
  
    int i, res;
    res = tab[0]; // res = *tab
    for(i=1;i<n;i++) {
        if(tab[i]>res) { // if(*(tab+i)<res) {
            res = tab[i]; // res = *(tab+i);
        }
    }
    return res;

}
