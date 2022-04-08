#include <iostream>

using namespace std;

void sum(int number);

int main(void) {
    int number;
    cout << "Число: ";
    cin >> number;
    sum(number);
}

void sum(int number) {
    static int result = 0;
    static int counter = 1;
    if ((number % counter) == 0 && (counter % 2) == 0) {
        result += counter;
    }
    if (counter > number) {
        cout << "Сумма четных делителей числа: " << result << endl;
    } else {
        counter++;
        sum(number);
    }
}