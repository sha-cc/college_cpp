#include <iostream>

using namespace std;

int sequence(int number, int first, int second);

int main(void) {
    int number, first, second;
    cout << "N = "; cin >> number;                  // номер члена, который нужно вычислить
    cout << "A0 = "; cin >> first;                  // нулевой член последовательности
    cout << "A1 = "; cin >> second;                 // первый член последовательности
    cout << sequence(number, first, second) << endl;
}

int sequence(int number, int first, int second) {
    switch (number) {
        case 0: return first;
        case 1: return second;
        default: return sequence(number - 1, first, second) * sequence(number - 2, first, second) * (-1);
    }
    return 0;
}