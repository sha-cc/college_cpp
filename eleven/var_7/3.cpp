#include <iostream>
#include <time.h>
using namespace std;
int main(void) {
    srand(time(0));
    int size;
    cout << "Введите размер массива: "; cin >> size;
    int *arr = (int*) calloc(size, sizeof(int));
    while (1) {
        char answer; 
        cout << "Заполнение массива вручную(m) или случайными числами(r): "; cin >> answer;
        if (answer == 'm') {
            for (int i = 0; i < size; i++) {
                cout << "arr[" << i <<"] = "; 
                cin >> arr[i];
            }
            break;
        } else if (answer == 'r') {
            for (int i = 0; i < size; i++) arr[i] = (int) rand() % 41 - 20;
            break;
        } else continue;
    }
    cout << "Массив arr[" << size << "]: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;

    // вставить число после минимального элемента
    int number;
    cout << "Число: "; cin >> number;
    int minElement = 20, minElementIndex = -1;
    for (int i = 0; i < size; i++)
        if (arr[i] < minElement) {
            minElement = arr[i];
            minElementIndex = i;
        }
    for (int i = size; i > minElementIndex; i--) arr[i] = arr[i - 1];
    arr[minElementIndex + 1] = number;
    arr = (int*) realloc(arr, size * sizeof(int));
    cout << "Массив arr[" << size << "], вставлено число " << number << " после минимального элемента: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl;
    free(arr);
}