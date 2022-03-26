#include <iostream>

using namespace std;

/* Функция, вычисляющая сумму цифр заданного числа */

void sum(int number);

int main(void) {
    int number;
    cout << "Number: "; cin >> number;
    sum(number);
}

void sum(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    cout << "Sum of digits: " << sum << endl;
}