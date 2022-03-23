#include <iostream>

using namespace std;

void nod(int a, int b);

int main(void) {
    nod(12, 2048);
}

void nod(int a, int b) {
    
    if (a == b) {
        cout << a << endl;
    } else if (a > b) {
        a = a - b;
        nod(a, b);
    } else {
        b = b - a;
        nod(a, b);
    }
}