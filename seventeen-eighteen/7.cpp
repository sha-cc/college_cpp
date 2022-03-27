#include <iostream>

using namespace std;

/* Нахождение НОД с помощью алгоритма Евклида */

void nod(int a, int b);

int main(void) {
    int a, b;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    nod(a, b);
}

void nod(int a, int b) {
    if (a == b) 
        cout << "Greatest Common Divisor = " << a << endl;
    else if (a > b) {
        a = a - b;
        nod(a, b);
    } else {
        b = b - a;
        nod(a, b);
    }
}