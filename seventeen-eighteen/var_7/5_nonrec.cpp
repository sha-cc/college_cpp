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
    int result, tmp1, tmp2;
    for (int i = 0; i < number - 1; i++) {
        if (i == 0) {
            result = (first + second) / 2;
            tmp2 = result;
        } else if (i == 1) {
            result = (second + tmp2) / 2;
            tmp1 = result;
        } else {
            result = (tmp1 + tmp2) / 2;
            tmp2 = tmp1;
            tmp1 = result;
        }
    }
    return result;
}