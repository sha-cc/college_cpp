#include <iostream>

using namespace std;

/* Функция, выводящая цифры заданного числа в обратном порядке */

void reverse(int number);

int main(void) {
    int number;
    cout << "Number: "; cin >> number;
    reverse(number);
}

void reverse(int number) {
    cout << "Reversed: ";
    while (number != 0) {
        cout << number % 10;
        number /= 10;
    }
    cout << endl;
}