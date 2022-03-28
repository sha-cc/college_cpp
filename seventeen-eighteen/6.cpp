#include <iostream>

using namespace std;

int sequence(int number);
int secondary(int number);

int main(void) {
    int number;
    cout << "N = "; cin >> number;
    cout << sequence(number) << endl;
}

int secondary(int number) {
    if (number == 0) return 1;
    else return secondary(number - 1) * (-1) + (number - 1) * sequence(number - 1);
}

int sequence(int number) {
    if (number == 0) return 1;
    else return 2 * secondary(number) - sequence(number - 1);
}