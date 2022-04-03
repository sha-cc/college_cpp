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
        arrOfNegatives[i] = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (arr[i][j] < 0) {
                arrOfNegatives[i] = j;
                break;
            }
        }

    cout << "\nИндексы первых отрицательных элементов в строках:" << endl;
    for (int i = 0; i < m; i++)
        cout << arrOfNegatives[i] << " ";
    cout << endl;

    // сортировка
    for (int i = 0; i < (m - 1); i++)
        for (int j = i; j < m; j++)
            if (arrOfNegatives[i] > arrOfNegatives[j]) {
                int tmp = arrOfNegatives[i];
                arrOfNegatives[i] = arrOfNegatives[j];
                arrOfNegatives[j] = tmp;

                int *tmp2 = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp2;
            }

    // вывод матрицы
    cout << "\nОтсортированный массив:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%5d ", arr[i][j]);
        cout << endl;
    }


    // максимальный элемент матрицы
    int maxElement = 0, columnWithMaxElement;
    // наименьший по модулю нечетный элемент
    int smallestOddNumber = 99, columnWithSmallestOddNumber;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > maxElement) {
                maxElement = arr[i][j];
                columnWithMaxElement = j;
            }
            if (abs(arr[i][j]) % 2 != 0 && abs(arr[i][j]) < smallestOddNumber) {
                smallestOddNumber = abs(arr[i][j]);
                columnWithSmallestOddNumber = j;
            }
        }

    cout << "\nМаксимальный элемент матрицы находится в столбце " << columnWithMaxElement << " (" << maxElement << ")";
    cout << "\nНаименьший по модулю нечетный элемент матрицы находится в столбце " << columnWithSmallestOddNumber << " (" << smallestOddNumber << ")" << endl;

    for (int i = 0; i < m; i++) {
        double temp = arr[i][columnWithMaxElement];
        arr[i][columnWithMaxElement] = arr[i][columnWithSmallestOddNumber];
        arr[i][columnWithSmallestOddNumber] = temp;
    }

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