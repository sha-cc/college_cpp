#include <iostream>

using namespace std;

/* Функция, вычисляющая произведение нечетных цифр заданного числа */

void thing(int number);

int main(void) {
    int number;
    cout << "Number: "; cin >> number;
    thing(number);
}

void thing(int number) {
    int product = 1;
    while (number != 0) {
        if (number % 10 % 2 != 0) product *= number % 10;
        number /= 10;
    }
    cout << "Sum of odd digits: " << product << endl;
}