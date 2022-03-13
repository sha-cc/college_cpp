#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

/* Найти последний элемент массива, по модулю не
превосходящий 1, заменить его нулем и поставить в начало
массива. */

int main(void) {

    // random seed
    srand(time(0));

    // размер массива - константа
    const int SIZE = 10;

    // создаем случайный массив с SIZE элементами и разбросом [-10; +10]
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 21 - 10;

    // выводим получившийся массив
    cout << "\nМассив arr[" << SIZE << "] из случайных элементов:\n";
    for (int i = 0; i < SIZE; i++)
        cout << "{" << arr[i] << "} ";
    printf("\n\n");

    int last = -1;
    for (int i = 0; i < SIZE; i++)
        if (abs(arr[i]) <= 1)
            last = i;

    if (last == -1) {
        cout << "В массиве нет элементов, по модулю не превосходящих 1\n";
        return 0;
    } else {
        arr[last] = 0;
    }

    for (int i = last; i > 0; i--) {
        int tmp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = tmp;
    }

    // выводим получившийся массив
    cout << "\nМассив arr[" << SIZE << "] из случайных элементов:\n";
    for (int i = 0; i < SIZE; i++)
        cout << "{" << arr[i] << "} ";
    printf("\n\n");
}