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
    double **arr = (double**) malloc(n * sizeof(double));

    // заполнение массива указателями
    for (int i = 0; i < n; i++)
        arr[i] = (double*) malloc(m * sizeof(double));

    // инициализация массива случайными числами
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = (double) (rand() % 400 - 199) / 2.0;    // (-100.0; 100.0)

    // вывод матрицы
    cout << "\n\033[92mИсходный массив:\033[94m" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%5.1f ", arr[i][j]);
        cout << endl;
    }



    // массив для сумм модулей элементов строк
    float *sumOfAbsolutes = (float*) malloc(m * sizeof(float));

    // инициализация массива нулями
    for (int i = 0; i < m; i++) sumOfAbsolutes[i] = 0;

    // заполнение массива суммами модулей элементов
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            sumOfAbsolutes[i] += abs(arr[i][j]);

    // вывод
    cout << "\n\033[92mСуммы модулей элементов строк массива:" << endl;
    for (int i = 0; i < m; i++) 
        cout << "\033[92m" << i << ": \033[94m"<< sumOfAbsolutes[i] << "   ";
    cout << "\n\n";


    // сортировка
    for (int i = 0; i < (m - 1); i++)
        for (int j = i; j < m; j++)
            if (sumOfAbsolutes[i] > sumOfAbsolutes[j]) {
                double tmp = sumOfAbsolutes[i];
                sumOfAbsolutes[i] = sumOfAbsolutes[j];
                sumOfAbsolutes[j] = tmp;

                double *tmp2 = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp2;
            }

    // вывод матрицы
    cout << "\033[92mОтсортированный массив:\033[94m" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%5.1f ", arr[i][j]);
        cout << endl;
    }


    int columnWithMaxNegNum = 0;        // столбец с максимальным отрицательным элементом
    int minNumber = 0;                  // столбец с минимальным элементом

    // поиск максимального отрицательного элемента
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] < 0 && arr[i][j] > arr[i][columnWithMaxNegNum])
                columnWithMaxNegNum = j;
    
    // поиск минимального элемента
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] < arr[i][minNumber]) minNumber = j;


    cout << "\n\033[92mСтолбец с максимальным отрицательным элементом: \033[94m" << columnWithMaxNegNum << endl;
    cout << "\033[92mСтолбец с минимальным элементом: \033[94m" << minNumber << endl;

    // перестановка столбцов
    for (int i = 0; i < m; i++) {
        double temp = arr[i][columnWithMaxNegNum];
        arr[i][columnWithMaxNegNum] = arr[i][minNumber];
        arr[i][minNumber] = temp;
    }

    cout << "\n\033[92mПерестановка столбцов:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("\033[94m%5.1f ", arr[i][j]);
        cout << "\n\033[0m";
    }

    // очистка памяти
    free(sumOfAbsolutes);
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}