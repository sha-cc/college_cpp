#include <iostream>

using namespace std;

/* Найти цифровой корень целого неотрицательного числа */

void digitalRoot(int a);

int main() {
    int number;
    cout << "Number: "; cin >> number;
    digitalRoot(number);
}

void digitalRoot(int number) {
    if (number < 10) cout << "Digital root: " << number << endl;
    else {
        int result = 0;
        while (number != 0) {
            result += number % 10;
            number /= 10;
        }
        digitalRoot(result);
    }
}