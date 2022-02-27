#include <iostream>
#include <time.h>

using namespace std;

/* Положительные элементы переставить в начало массива и расположить в порядке возрастания */

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
    cout << "\n\033[94mМассив \033[92marr[\033[94m" << SIZE << "\033[92m]\033[94m из случайных элементов:\033[0m\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\033[92m{\033[0m" << arr[i] << "\033[92m}\033[0m ";
    }
    printf("\n\n");

    // сортировка выбором
    for (int i = SIZE - 1; i >= 0; i--) {
        if (arr[i] < 0) {
            int temp = i;
            int max = arr[i];
            int max_ind = -1;
            for (int j = i + 1; j < SIZE; j++) {
                if (arr[j] > 0) {
                    int t = arr[j];
                    arr[j] = arr[temp];
                    arr[temp] = t;
                    temp = j;
                }          
            }
        }
    }

    // узнаем последний положительный элемент в получившемся массиве
    int last_positive = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < 0) {
            last_positive = i - 1;
            break;
        }
    } 

    // если все элементы массива - положительные числа, то сортируем весь массив
    if (last_positive == 0)
        last_positive == SIZE;

    // пузырьковая сортировка положительных элементов по возрастанию
    int temp;
    for (int i = 0; i <= last_positive; i++) {
        for (int j = 0; j < last_positive; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // выводим получившийся массив
    cout << "\n\033[94mПолучившийся массив \033[92marr[\033[94m" << SIZE << "\033[92m]\033[94m:\033[0m\n";
    for (int i = 0; i < SIZE; i++)
        cout << "\033[92m{\033[0m" << arr[i] << "\033[92m}\033[0m ";
    printf("\n");    

}