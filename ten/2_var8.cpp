#include <iostream>
#include <time.h>

using namespace std;

/* Вывести элементы двумерного массива из левого нижнего угла против часовой стрелки по спирали. */

int main(void) {

    // случайное число для rand()
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


    // https://www.codespeedy.com/print-a-matrix-in-counter-clockwise-spiral-in-cpp/
    int count = 0;
    int total = arrX * arrY;

    int i, a = 0, b = 0, c = arrX, d = arrY;
    
    while (1) {
        // Print the last row from the remaining rows  
        for (i = b; i < d; ++i) { 
            cout << arr[c - 1][i] << " "; 
            count++; 
        } 
        c--; 
  
        if (count == total) 
            break; 

        // Print the last column from the remaining columns  
        if (a < c) { 
            for (i = c - 1; i >= a; --i) { 
                cout << arr[i][d - 1] << " "; 
                count++; 
            } 
            d--; 
        }

        if (count == total) 
            break; 

        // Print the first row  from the remaining rows  
        if (b < d) { 
            for (i = d - 1; i >= b; --i) { 
                cout << arr[a][i] << " "; 
                count++; 
            } 
            a++; 
        }
        
        if (count == total) 
            break;
  
        // Print first column from remaining
        for (i = a; i < c; ++i) { 
            cout << arr[i][b] << " "; 
            count++; 
        } 
        b++;  

        if (count == total) 
            break; 
    }

    printf("\n");

}