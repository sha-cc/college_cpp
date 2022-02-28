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

}