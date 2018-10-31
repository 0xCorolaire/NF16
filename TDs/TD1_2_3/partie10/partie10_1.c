
void test1() {
    int a, b;
    b= 3;
    a=b;//&a = b
}

void test2() {
    int *p, a;
    a=4;
    p = &a; // p = a
    *p = *p+1;
}

void test3() {
    int *p, a;
    a = 2;
    p = &a;//*p = a Pointeur non initialisé !!!
}

int main() {

    test1();
    test2();
    test3();
    return 0;
}
