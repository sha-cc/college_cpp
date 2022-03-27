#include <iostream>
#include <string>
 
using namespace std;

/* Найти максимальную цифру целого неотрицательного числа и её позицию в этом числе */

void maxDigit(long int number);

int main() {
    long int number;
    cout << "Number: "; cin >> number;
    maxDigit(number);
}

// явно не самый легкий способ сделать это

void maxDigit (long int number) {

    int length = to_string(number).length();        // количество цифр в числе
    int *arr = (int*) malloc(length * sizeof(int)); // каждая цифра числа - элемент массива
    int result = 0;                                 // самая большая цифра
    int position = 0;                               // ее позиция

    for (int i = 0; i < length; i++) {
        arr[i] = number % 10;
        number /= 10;
    }

    for (int i = length; i > 0; i--)
        if (arr[i] >= result) {
            result = arr[i];
            position = i;
        }

    cout << "Max. digit: " << result << endl;
    cout << "Position: " << position << endl;

    free(arr);
}