#include <iostream>
 
using namespace std;

/* Найти максимальную цифру целого неотрицательного числа и её позицию в этом числе */

void maxDigit(long int number);

int main() {
    long int number;
    cout << "Число: "; cin >> number;
    maxDigit(number);
}

void maxDigit (long int number) {

    int result = 0, position = 0, positionMax;

    while (number != 0) {
        if (number % 10 >= result) {
            result = number % 10;
            positionMax = position;
        }
        position++;
        number /= 10;
    }

    cout << "\nмаксимальная цифра - " << result << ", её позиция - " << positionMax << endl;

}