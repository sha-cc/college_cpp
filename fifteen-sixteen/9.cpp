#include <iostream>

using namespace std;

/* Функция, меняющая местами значения двух целых чисел */

int swap(int *one, int *two);

int main(void) {
    int one, two;
    cout << "one = "; cin >> one;
    cout << "two = "; cin >> two;
    swap(&one, &two);
    cout << "Now one = " << one << " and " << "two = " << two << endl;
}

int swap(int *one, int *two) {
    int tmp = *two;
    *two = *one;
    *one = tmp;
    return 0;
}