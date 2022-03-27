#include <iostream>

using namespace std;

/* Вывести цифры числа, начиная со старшего разряда */

void reverse(int number);

int main(void) {
    int number;
    cout << "Number = "; cin >> number;
    reverse(number);
}

void reverse(int number) {
    if (number >= 10) 
        reverse(number / 10);
    int digit = number % 10;
    cout << digit << endl;
}