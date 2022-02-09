#include <iostream>
#include <time.h>

using namespace std;

int main(void) {

    // random seed
    srand(time(0));

    const int SIZE = 10;                                        // размер массива - константа

    float arr[SIZE];                                            // создаем массив

    while (1) {
        char input;
        cout << "\n\033[94mИнициализация\033[0m: случайная\033[92m(r)\033[0m или вручную\033[92m(m)\033[0m? ";
        cin >> input;

        if (input == 'm') {                                     // m - manual
            for (int i = 0; i < SIZE; i++) {
                printf("\033[0mВведите \033[95m%d\033[0m элемент массива: \033[91m", i);
                cin >> arr[i];
                if (i == SIZE)
                    goto brk;                                   // break
            }
        } else if (input == 'r') {                              // r - random
            for (int i = 0; i < SIZE; i++) {
                arr[i] = (float(rand())/float(RAND_MAX)) * 6.9; // наполнение массива
                if (i == SIZE)
                    goto brk;                                   // break
            }
        } else { continue; }                                    // игнорирование плохого ввода

        brk: break;                                             // да, я знаю, что goto не нужно использовать
    }

    // вывод содержимого
    printf("\n\033[0;1mМассив \033[1;34marr\033[0;1m:\033[0m\n\n");
    for (int i = 0; i < SIZE; i++) {
        printf("\033[94marr[\033[0;91m%d\033[0;94m]\033[0m = %.3f\n", i, arr[i]);
    }
}
