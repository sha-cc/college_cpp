#include <iostream>

using namespace std;

void countDigits(unsigned long int number);

int main(void) {
    unsigned long int number;
    cout << "Натуральное число: "; cin >> number;
    countDigits(number);
}

void countDigits(unsigned long int number) {
    int counter = 0;
    while (number != 0) {
        number /= 10;
        counter++;
    }
    cout << "Количество цифр числа: " << counter << endl;
}