#include <iostream>

using namespace std;

/* Функция, вычисляющая сумму нечетных чисел в диапазоне от m до n */

void sum(int m, int n);

int main(void) {
    int m, n;
    cout << "m = "; cin >> m;
    cout << "n = "; cin >> n;
    sum(m, n);
}

void sum(int m, int n) {
    int sum = 0;
    for (int i = m; i < n; i++) if (i % 2 != 0) sum += i;
    cout << "Sum of odd numbers between " << m << " and " << n << " is " << sum << endl;
}