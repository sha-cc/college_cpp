#include <iostream>

using namespace std;

/* Вычислить произведение нечетных цифр числа */

int productOfOdds(int number);
int product = 1;

int main(void) {
    int number;
    cout << "Number: "; cin >> number;
    productOfOdds(number);
}

int productOfOdds(int number) {
    if (number < 1) {
        cout << "Product of odd digits of the number: " << product << endl;
        return 0;
    } else {
        if ((number % 10) % 2 != 0) product *= (number % 10);
        number /= 10;
        productOfOdds(number);
    }
    return 0;
}