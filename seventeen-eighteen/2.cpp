#include <iostream>
#include <string>

using namespace std;

int digitalRoot(long a);

int main() {
    int number;
    cout << "Number: ";
    cin >> number;
    digitalRoot(number);
    return 0;
}

int digitalRoot(long number) {
    int result;
    int length = to_string(number).length();
    if (length == 1) {
        cout << "Digital root: " << result << endl;
        return 0;
    }
    for (int i = 0; i < length; i++) {
        result += (number % 10);
        number /= 10;
    }
    digitalRoot(result);
}