#include <iostream>

using namespace std;

/* Функция, вычисляющая максимум двух целых чисел */

void maximum(int one, int two);

int main(void) {
    int one, two;
    cout << "First number: "; cin >> one;
    cout << "Second number: "; cin >> two;
    maximum(one, two);
}

void maximum(int one, int two) {
    if (one == two) cout << "Same numbers";
    else {
        int maximum = one > two? one: two;
        cout << "Maximum: " << maximum << endl;
    }
}