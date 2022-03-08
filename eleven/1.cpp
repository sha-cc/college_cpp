#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(void) {

    // случайное число для rand()
    srand(time(0));

    // размер массива, определяется пользователем
    int size;
    printf("\n\033[92mВведите размер массива: \033[94m");
    scanf("%d", &size);

    // объявление массива и выделение памяти под него
    int *arr = (int*) calloc(size, sizeof(int));

    while (1) {
        printf("\n\033[92mЗаполнение массива: \033[95mвручную (m) \033[92mили \033[95mслучайными числами (r)\033[92m: \033[94m");
        char answer; cin >> answer;
        if (answer == 'm') {
            // заполнение массива вручную
            for (int i = 0; i < size; i++) {
                printf("\033[92marr[\033[94m%d\033[92m]\033[92m = \033[93m", i);
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
    printf("\n\033[92mМассив arr[\033[94m%d\033[92m]:\033[0m\n", size);
    for (int i = 0; i < size; i++)
        printf("\033[93m%d ", arr[i]);
    printf("\033[0m\n\n");

    // освобождение памяти
    free(arr);
}