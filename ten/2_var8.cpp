#include <iostream>
#include <time.h>

using namespace std;

/* Вывести элементы двумерного массива из левого нижнего угла 
против часовой стрелки по спирали. */

int main(void) {

    // random seed
    srand(time(0));

    // размер массива - константы
    const int arrX = 6;
    const int arrY = 6;

    // объявление массива
    int arr [arrX] [arrY];

    // заполнение матрицы случайными числами от –15 до 15
    for (int i = 0; i < arrX; i++)
        for (int j = 0; j < arrY; j++)
            arr[i][j] = rand() % 31 - 15;

    // вывод исходной матрицы
    printf("\033[92m\n ");
    for (int i = 0; i < 37; i++)
        printf("-");
    printf("\033[0m\n");
    for (int i = 0; i < arrX; i++) {
        for (int j = 0; j < arrY; j++)
            printf(" \033[92m|\033[94m %3d", arr[i][j]);
        printf(" \033[92m| \r\n");
    }
    printf(" ");
    for (int i = 0; i < 37; i++)
        printf("-");
    printf("\033[0m\n");


    // https://www.geeksforgeeks.org/print-given-matrix-counter-clock-wise-spiral-form/

    int k = 5, l = 0;
    int m = arrX, n = arrY;
 
    //  k - starting row index
    //    m - ending row index
    //    l - starting column index
    //    n - ending column index
 
    // initialize the count
    int cnt = 0;
 
    // total number of
    // elements in matrix
    int total = arrX * arrY;

    while (l < n) {
        if (cnt == total)
            break;
 
        // Print the first column
        // from the remaining columns
        for (int i = k; i < m; ++i) {
            cout << arr[i][l] << " ";
            cnt++;
        }
        l++;
 
        if (cnt == total)
            break;
 
        // Print the last row from
        // the remaining rows
        for (int i = l; i < n; ++i) {
            cout << arr[m - 1][i] << " ";
            cnt++;
        }
        m--;
 
        if (cnt == total)
            break;
 
        // Print the last column
        // from the remaining columns
        if (k < m) {
            for (int i = m - 1; i >= k; --i) {
                cout << arr[i][n - 1] << " ";
                cnt++;
            }
            n--;
        }
 
        if (cnt == total)
            break;

        // Print the first row
        // from the remaining rows
        if (l < n) {
            for (int i = n - 1; i >= l; --i) {
                cout << arr[k][i] << " ";
                cnt++;
            }
            k++;
        }
    }

    printf("\n");

}