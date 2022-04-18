#include <iostream>

using namespace std;

/* Вывести последовательность символов в виде прямоугольника размером mxn */

void rectangle(int m, int n);

int main(void) {
    int m, n;
    cout << "m = "; cin >> m;
    cout << "n = "; cin >> n;
    rectangle(m, n);
}

void rectangle(int m, int n) {
    char abc[3] = {'a', 'b', 'c'};
    int identifier = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << abc[identifier % 3];
            identifier++;
        }
        cout << endl;
    }
}