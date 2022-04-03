#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

int main(void) {

    // случайное число для функции rand()
    srand(time(0));

    int m = 5;  // число строк
    int n = 5;  // число столбцов

    // объявление динамического массива указателей
    int **arr = (int**) malloc(n * sizeof(int*));

    // заполнение массива указателями
    for (int i = 0; i < n; i++)
        arr[i] = (int*) malloc(m * sizeof(int));

    // инициализация массива случайными числами
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = (int) rand() % 200 - 99;    // (-100.0; 100.0)

    // вывод матрицы
    cout << "\nИсходный массив:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%5d ", arr[i][j]);
        cout << endl;
    }


    // массив для индексов первых отрицательных элементов в строке
    int *arrOfNegatives = (int*) (malloc(m * sizeof(int)));

    for (int i = 0; i < m; i++)
        arrOfNegatives[i] = 0;          // заполнение массива нулями

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (arr[i][j] < 0) {        // если элемент матрицы меньше 0
                arrOfNegatives[i] = j;  // записываем его индекс
                break;                  // и выходим из этого цикла (переход на следующую строку)
            }
        }

    // вывод
    cout << "\nИндексы первых отрицательных элементов в строках:" << endl;
    for (int i = 0; i < m; i++)
        cout << arrOfNegatives[i] << " ";
    cout << endl;

    // пузырьковая сортировка
    for (int i = 0; i < (m - 1); i++)                       // этот алгоритм сортировки полностью
        for (int j = i; j < m; j++)                         // скопирован из теории работы. Если
            if (arrOfNegatives[i] > arrOfNegatives[j]) {    // честно, я даже не вникал в то, как он
                int tmp = arrOfNegatives[i];                // работает. Судя по всему, он универсален
                arrOfNegatives[i] = arrOfNegatives[j];      // и будет работать для всех вариантов
                arrOfNegatives[j] = tmp;                    // в этой практической (если изменять
                                                            // названия переменных и типы данных,
                int *tmp2 = arr[i];                         // конечно). Единственное, что нужно
                arr[i] = arr[j];                            // знать про этот алгоритм - то, что
                arr[j] = tmp2;                              // это сортировка строк по возрастанию
            }                                               // пузырьковым методом сортировки

    // вывод матрицы
    cout << "\nОтсортированный массив:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%5d ", arr[i][j]);
        cout << endl;
    }


    // максимальный элемент матрицы, начальное значение - маленькое число
    int maxElement = 0, columnWithMaxElement;
    // наименьший по модулю нечетный элемент, начальное значение - большое число
    int smallestOddNumber = 99, columnWithSmallestOddNumber;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > maxElement) {   // если элемент больше, чем максимальный известный
                maxElement = arr[i][j];     // то записываем его, как максимальный
                columnWithMaxElement = j;   // и записываем столбец, в котором он находится
            }
            // если модуль числа - нечетное число и он меньше минимального известного
            if (abs(arr[i][j]) % 2 != 0 && abs(arr[i][j]) < smallestOddNumber) {
                smallestOddNumber = abs(arr[i][j]);     // записываем модуль этого числа
                columnWithSmallestOddNumber = j;        // и столбец, в котором он находится
            }
        }

    // вывод
    cout << "\nМаксимальный элемент матрицы находится в столбце " << columnWithMaxElement << " (" << maxElement << ")";
    cout << "\nНаименьший по модулю нечетный элемент матрицы находится в столбце " << columnWithSmallestOddNumber << " (" << smallestOddNumber << ")" << endl;

    // перемещаем элементы столбцов с этими элементами с помощью дополнительной переменной
    for (int i = 0; i < m; i++) {
        int temp = arr[i][columnWithMaxElement];
        arr[i][columnWithMaxElement] = arr[i][columnWithSmallestOddNumber];
        arr[i][columnWithSmallestOddNumber] = temp;
    }

    // вывод
    cout << "\nПерестановка столбцов:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%5d ", arr[i][j]);
        cout << endl;
    }

    // очистка памяти
    free(arrOfNegatives);
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
    
}