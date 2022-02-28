#include <iostream>
#include <time.h>

using namespace std;

/* Нулевые элементы переставить в конец массива, а
остальные расположить в порядке убывания. */

int main(void) {

    // random seed
    srand(time(0));

    // размер массива - константа
    const int SIZE = 10;

    // создаем случайный массив с SIZE элементами и разбросом [-10; +10]
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 21 - 10;
    }

    // выводим получившийся массив
    cout << "\nМассив arr[" << SIZE << "] из случайных элементов:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "{" << arr[i] << "} ";
    }
    cout << endl;    

    // пузырьковая сортировка
    for (int i = 0; i < (SIZE-1); i++) {
        for (int j = 0; j < (SIZE - i - 1); j++)
            if (arr[j] < arr[j + 1]) {
                double tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
    }

    // переставляем нули в конец массива
    int j = 0;
    for (int i = 0; i < SIZE - j; i++)
        if (arr[i] == 0) {
            j++;
            arr[i] = arr[SIZE - j];
            arr[SIZE - j] = 0;
        }

    // выводим получившийся массив
    cout << "\nПолучившийся массив arr[" << SIZE << "]:\n";
    for (int i = 0; i < SIZE; i++)
        cout << "{" << arr[i] << "} ";
    cout << endl;    

}