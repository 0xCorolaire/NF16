int test() {
    int *p, a; // On suppose que l'adresse de a est 2000
    a = 10; //a=10, p=?
    p = &a; //a=10, p=2000, *p=10
    a = a -1; //a=9, p=2000, *p=9 
    *p = a+1; //a=10, p=2000, *p=10 
    *p = *p+1;//a=11, p=2000, *p=11
    p=p+1;//a=11, p=2004, *p=?
}


int main() {
    return 0;
}
