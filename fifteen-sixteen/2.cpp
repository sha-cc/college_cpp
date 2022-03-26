#include <iostream>

using namespace std;

/* Функция, вычисляющая максимум трех вещественных чисел */

void maximum(float one, float two, float three);

int main(void) {
    float one, two, three;
    cout << "First number: "; cin >> one;
    cout << "Second number: "; cin >> two;
    cout << "Third number: "; cin >> three;
    maximum(one, two, three);
}

void maximum(float one, float two, float three) {
    if (one == two && two == three) cout << "Same numbers" << endl;
    else {
        float maximum = (one > two)? ((one > three)? one : three) : ((two > three)? two : three);
        cout << "Maximum: " << maximum << endl;
    }
}