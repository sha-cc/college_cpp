#include <iostream>

using namespace std;

void reverse(int number);

int main(void) {
    reverse(16543);
}

void reverse(int number) {
    if (number >= 10) 
        reverse(number / 10);
    int digit = number % 10;
    cout << digit << endl;
}