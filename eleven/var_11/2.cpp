#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(void) {

    // случайное число для rand()
    srand(time(0));

    // размер массива, определяется пользователем
    int size;
    printf("\nВведите размер массива: ");
    scanf("%d", &size);

    // объявление массива и выделение памяти под него
    int *arr = (int*) calloc(size, sizeof(int));

    while (1) {
        printf("\nЗаполнение массива: вручную (m) или случайными числами (r): ");
        char answer; cin >> answer;
        if (answer == 'm') {
            // заполнение массива вручную
            for (int i = 0; i < size; i++) {
                printf("arr[%d] = ", i);
                scanf("%d", &arr[i]);
            }
            break;
        } else if (answer == 'r') {
            // заполнение массива случайно целыми числами из промежутка [-20; 20]
            for (int i = 0; i < size; i++)
                arr[i] = (int) rand() % 41 - 20;
            break;
        } else {continue;}
    }

    // вывод массива
    printf("\nМассив arr[%d]:\n", size);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n\n");



    /* Удалить элементы, стоящие между первым и последним положительными элементами */
    int firstPositive = -1, lastPositive;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && firstPositive == -1)
            firstPositive = i;
        else if (arr[i] > 0)
            lastPositive = i;
    }

    for (int i = 0; i < (size - lastPositive); i++)
        arr[firstPositive + i + 1] = arr[lastPositive + i];

    size = (size - lastPositive) + (size - (size - firstPositive));

    arr = (int*) realloc(arr, size * sizeof(int));

    // вывод массива
    printf("Массив arr[%d], удалены элементы, стоящие между первым\nи последним положительными элементами:\n", size);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    // освобождение памяти
    free(arr);
}