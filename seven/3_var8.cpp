#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

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
    printf("\n\033[94mМассив \033[92marr[\033[94m%d\033[92m]\033[94m из случайных элементов:\033[0m\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("\033[92m[\033[0m%d\033[92m]\033[0m", arr[i]);
    }
    printf("\n\n");

    // заменяем отрицательные элементы их квадратами
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < 0) {
            arr[i] = pow(arr[i], 2);
        }
    }
    printf("\033[94mОтрицательные элементы заменены их квадратами:\033[0m\n");
    for (int i = 0; i < SIZE; i++) {
        printf("\033[92m[\033[0m%d\033[92m]\033[0m", arr[i]);
    }
    printf("\n\n");
}