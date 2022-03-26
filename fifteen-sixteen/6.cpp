#include <iostream>

using namespace std;

/* Функция, выводящая числа в диапазоне от m до n, сумма цифр которых не превосходит 9 */

void discriminator9000(int m, int n);

int main(void) {
    int m, n;
    cout << "m = "; cin >> m;
    cout << "n = "; cin >> n;
    discriminator9000(m, n);
}

void discriminator9000(int m, int n) {
    for (int i = m; i < n; i++) {
        int temp = i, digiSum = 0; 
        while (temp != 0) {
            digiSum += temp % 10;
            temp /= 10;
        }
        if (digiSum <= 9) cout << i << " ";
    }
    cout << endl;
}