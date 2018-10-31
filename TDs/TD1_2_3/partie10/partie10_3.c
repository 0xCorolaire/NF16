int test() {
    int *p1, *p2,tab[2]; // Adresse de tab[0] est 2000
    tab[0] = 3; // Valeur 3 affectée à l'adresse 2000
    tab[1] = 5; // Valeur 5 affectée à l'adresse 2000+4 = 2004
    p1 = tab; // p1 = 2000
    p2 = p1+1; // p2 = 2004
}


int main() {
    test();
    return 0;
}
