#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str; int k, m;
    cout << "Строка: "; cin >> str;
    cout << "K = "; cin >> k; cout << "M = "; cin >> m;

    for (int i = k; i < m; i++) {
        int temp = str[i];
        str[i] = str[m];
        str[m] = temp;
    }

    for (int i = 0; i < str.length(); i++) cout << str[i];
    cout << endl;
}