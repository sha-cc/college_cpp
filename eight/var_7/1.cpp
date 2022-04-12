#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;
int main(void) {
    srand(time(0));
    const int SIZE = 10;
    float arr[SIZE];
    while (1) {
        char input;
        cout << "Инициализация: случайная(r) или вручную(m)? ";
        cin >> input;
        if (input == 'm')
            for (int i = 0; i < SIZE; i++) {
                cout << "Введите " << i << " элемент массива: ";
                cin >> arr[i];
            }
        else if (input == 'r')
            for (int i = 0; i < SIZE; i++)
                arr[i] = (float(rand())/float(RAND_MAX)) * 6.9;
        else continue;
        break;
    }
    cout << "Массив arr[" << SIZE << "]:" << endl;
    for (int i = 0; i < SIZE; i++)
        printf("arr[%d] = %.3f\n", i, arr[i]);
}
