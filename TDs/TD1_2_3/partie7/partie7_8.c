#include <stdio.h>
#define NROW 3
#define NCOL 4 
int main() {

    int tab[NROW][NCOL];
    int val = 12;
    int i, j;
    
    for(i=0; i<NROW; i++) {
        for(j=0; j<NCOL; j++) {
            tab[i][j] = val;
            val++;
        }
    }

   
    for(i=0; i<NROW; i++) {
        for(j=0; j<NCOL; j++) {
            printf("tab[%d][%d] = %d\n", i, j, tab[i][j]);
        }
    }
        



    return 0;
}
