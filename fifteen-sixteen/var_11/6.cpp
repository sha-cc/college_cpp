#include <iostream>

using namespace std;

void thing(void);

int main(void) {
    thing();
}

void thing(void) {
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; i++) {
        cout << alphabet[i];
        int temp = i;
        while (temp != 0) {
            cout << alphabet[temp - 1];
            temp--;
        }
        cout << endl;
    }
}