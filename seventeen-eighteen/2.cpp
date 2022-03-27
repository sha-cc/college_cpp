#include <iostream>

using namespace std;

int digitalRoot(long a);

int main() {
    int number;
    cout << "Number: "; cin >> number;
    digitalRoot(number);
}

int digitalRoot(long number) {
    int result;
    if (number < 10) {
        cout << "Digital root: " << result << endl;
    } else {
        while (number != 0) {
            result += number % 10;
            number /= 10;
        }
        digitalRoot(result);
    }
    return 0;
}