#include <iostream>
#include <time.h>
using namespace std;
int main(void) {
    srand(time(0));
    const int arrX = 6, arrY = 6;
    int arr[arrX][arrY];
    for (int i = 0; i < arrX; i++)
        for (int j = 0; j < arrY; j++)
            arr[i][j] = rand() % 31 - 15;
    for (int i = 0; i < arrX; i++) {
        for (int j = 0; j < arrY; j++) printf("%5d", arr[i][j]);
        printf("\n\n");
    }
    int sumOfElements[arrX] = {0};
    for (int i = 0; i < arrX; i++)
        for (int j = 0; j < arrY; j++)
            sumOfElements[i] += arr[i][j];
    int maxSumOfElements = -15, stringWithMaxSumOfElements = -1;
    for (int i = 0; i < arrX; i++)
        if (sumOfElements[i] > maxSumOfElements) {
            maxSumOfElements = sumOfElements[i];
            stringWithMaxSumOfElements = i;
        }
    cout << "Массив из строки с максимальной суммой элементов:" << endl;
    for (int i = 0; i < arrX; i++) cout << arr[stringWithMaxSumOfElements][i] << " ";
    cout << endl;
    int positiveElementsCount[arrY] = {0};
    for (int i = 0; i < arrX; i++)
        for (int j = 0; j < arrY; j++) {
            if (arr[i][j] > 0)
                positiveElementsCount[j]++;
        }
    cout << "\nМассив, равный количеству положительных элементов в столбцах:" << endl;
    for (int i = 0; i < arrY; i++) cout << positiveElementsCount[i] << " ";
    cout << endl;
}