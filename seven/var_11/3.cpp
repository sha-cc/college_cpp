#include <iostream>     // библиотека ввода-вывода C++
#include <time.h>       // библиотека, дающая доступ к системному времени

using namespace std;

/* Элементы, являющиеся локальными минимумами, заменить на среднее арифметическое их соседей */

int main() {

    // генерация случайного числа для функции rand()
    srand(time(0));

    // размер массива - константа
    const int SIZE = 10;

    // объявляем массив, элементы в нем - целые числа (int)
    int arr[SIZE];

    // инициализация массива, цикл с предусловием
    for (int i = 0; i < SIZE; i++) {
        // находим остаток от деления случайного числа на 21 (теперь число входит в [0; 20]) и вычитаем 10 из него (входит в [-10; 10])
        arr[i] = rand() % 21 - 10;                  // присваиваем только что сгенерированное число каждому элементу
    }

    // выводим получившийся массив
    cout << "Массив arr[" << SIZE << "] из случайных элементов:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "[" << arr[i] << "] ";              // [1] [2] [3] [...]
    }
    cout << "\n\n";                                 // дважды переходим на новую линию

    // само задание
    for (int i = 1; i < SIZE; i++) {
        // если этот Элемент меньше, чем Элемент + 1, и (&&) меньше, чем Элемент -1
        if(arr[i] < arr[i+1] && arr[i] < arr[i-1]) {
            arr[i] = (arr[i+1] + arr[i-1]) / 2;     // то заменяем его на среднее арифметическое его соседей
        }
    }

    // вывод
    cout << "Элементы, являющиеся локальными минимумами, заменены на среднее арифметическое их соседей:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "[" << arr[i] << "] ";              // [1] [2] [3] [...]
    }
    cout << "\n";
}