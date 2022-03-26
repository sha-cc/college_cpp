#include <iostream>
#include <cmath>

using namespace std;

/* Функция, вычисляющая корни квадратного уравнения без использования операций ввода/вывода данных */

const char *root(float a, float b, float c, float *x1, float *x2);

int main(void) {
    float a, b, c, x1, x2;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;

    if (root(a, b, c, &x1, &x2) == "err_no_root") cout << "\nRoot not found" << endl;
    else if (x1 == x2) cout << "\nx = " << x1 << endl;
    else cout << "\nx1 = " << x1 << endl << "x2 = " << x2 << endl;
}

const char *root(float a, float b, float c, float *x1, float *x2) {
    float D = pow(b, 2) - 4 * a * c;
    if (D > 0) {
        *x1 = ((-b) + sqrt(D)) / (2 * a);
        *x2 = ((-b) - sqrt(D)) / (2 * a);
    }
    else if (D == 0) *x1 = *x2 = -(b / (2 * a));
    else if (D < 0) return "err_no_root";
    return 0;
}