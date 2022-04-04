#include <iostream>
 
using namespace std;

/* Найти максимальную цифру целого неотрицательного числа и её позицию в этом числе */

int maxDigit(long int number);

int main() {
    long int number;
    cout << "Число: "; cin >> number;
    maxDigit(number);
}

int maxDigit (long int number) {
    static int position = 0;            // позиция цифры для текущей итерации
    static int positionMax = 0;         // позиция максимальной цифры
    static int max = 0;                 // максимальная цифра
    if (number == 0) {
        cout << "\nмаксимальная цифра - " << max << ", её позиция - " << positionMax << endl;
        return 0;
    }
    else if (number % 10 > max) {
        max = number % 10;
        positionMax = position;
    }
    position++;
    number /= 10;
    maxDigit(number);
    return 0;
}