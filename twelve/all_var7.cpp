#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;
int main(void) {
    srand(time(0));
    int m = 10, n = 10;
    int **arr = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) arr[i] = (int*) malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = (int) rand() % 19 - 9;
    cout << "\nИсходный массив:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) printf("%3d ", arr[i][j]);
        cout << endl;
    }
    int *zeroIndexes = (int*) malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) zeroIndexes[i] = -1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) 
            if (arr[i][j] == 0) {
                zeroIndexes[i] = j;
                break;
            }
    cout << "\nИндексы первых нулевых элементов в строках:" << endl;
    for (int i = 0; i < m; i++) {
        if (zeroIndexes[i] == -1) cout << i << ": (нет)" << "   ";
        else cout << i << ": "<< zeroIndexes[i] << "   ";
    }
    cout << endl << endl;
    for (int i = 0; i < (m - 1); i++)
        for (int j = i; j < m; j++)
            if (zeroIndexes[i] > zeroIndexes[j]) {
                int tmp = zeroIndexes[i];
                zeroIndexes[i] = zeroIndexes[j];
                zeroIndexes[j] = tmp;
                int *tmp2 = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp2;
            }
    cout << "Отсортированный массив:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) printf("%3d ", arr[i][j]);
        cout << endl;
    }

    int maxEvenNumber = -10, maxEvenNumberIndex = -1, smallestNumber = 10, smallestNumberIndex = -1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (arr[i][j] % 2 == 0 && arr[i][j] > maxEvenNumber) {
                maxEvenNumber = arr[i][j];
                maxEvenNumberIndex = j;
            }
            if (abs(arr[i][j]) < smallestNumber) {
                smallestNumber = arr[i][j];
                smallestNumberIndex = j;
            }
        }
    cout << "\nСтолбец с максимальным четным элементом матрицы (" << maxEvenNumber << "): " << maxEvenNumberIndex << endl;
    cout << "Столбец с наименьшим по модулю элементом (" << smallestNumber << "): " << smallestNumberIndex << endl;
    for (int i = 0; i < m; i++) {
        int temp = arr[i][maxEvenNumberIndex];
        arr[i][maxEvenNumberIndex] = arr[i][smallestNumberIndex];
        arr[i][smallestNumberIndex] = temp;
    }
    cout << "\nПерестановка столбцов:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) printf("%3d ", arr[i][j]);
        cout << endl;
    }
    free(zeroIndexes);
    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);
}