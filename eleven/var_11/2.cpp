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

    // переменная firstPositive не должна быть равно числу, входящему в промежуток от 0 до size
    int firstPositive = -1, lastPositive;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && firstPositive == -1)  // если элемент > 0 и первый положительный элемент все еще не найден
            firstPositive = i;                  // то записываем индекс первого положительного элемента
        else if (arr[i] > 0)                    // иначе, если элемент > 0
            lastPositive = i;                   // то записываем его индекс (будет меняться несколько раз)
    }

    for (int i = 0; i < (size - lastPositive); i++) // от 0 до количества элементов между первым и последним положительными
        // перемещаем посл. положительный элемент и все, стоящие за ним, на места сразу после первого положительного
        arr[firstPositive + i + 1] = arr[lastPositive + i];

    // назначение нового размера массива (если не делать +1, то последний элемент не войдет в новый массив)
    size = (size - lastPositive) + (size - (size - firstPositive)) + 1;

    arr = (int*) realloc(arr, size * sizeof(int));  // перераспределение памяти с realloc

    // вывод массива
    printf("Массив arr[%d], удалены элементы, стоящие между первым\nи последним положительными элементами:\n", size);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    // освобождение памяти
    free(arr);
}