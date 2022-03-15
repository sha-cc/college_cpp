#include <iostream>
#include <time.h>

using namespace std;

/* Найти первый нулевой элемент массива, заменить его индексом и поставить в конец массива */

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
    cout << "\n\033[94mМассив \033[92marr[\033[94m" << SIZE << "\033[92m]\033[94m из случайных элементов:\033[0m\n";
    for (int i = 0; i < SIZE; i++)
        cout << "\033[92m{\033[0m" << arr[i] << "\033[92m}\033[0m ";
    printf("\n\n");

    // ищем первый нулевой элемент
    int first_null = -1;
    for (int i = 0; i < SIZE; i++)
        if (arr[i] == 0) {
            first_null = i;
            break;
        }
    if (first_null == -1) {
        cout << "\033[1;33mВ массиве нет нулевых элементов\033[0m\n";
        return 0;
    }
    
    // заменяем его индексом
    arr[first_null] = first_null;

    // пузырьковая сортировка
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < (SIZE - 1); j++)
            if (arr[j] == first_null) {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp; 
            }

    // выводим получившийся массив
    cout << "\n\033[94mПолучившийся массив \033[92marr[\033[94m" << SIZE << "\033[92m]\033[94m:\033[0m\n";
    for (int i = 0; i < SIZE; i++) {
        if (i == 9) {
            cout << "\033[1;41;37m{" << arr[i] << "}\033[0m ";
        } else {
            cout << "\033[92m{\033[0m" << arr[i] << "\033[92m}\033[0m ";
        }
    }
    printf("\n");    

}