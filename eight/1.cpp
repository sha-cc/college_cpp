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

        if (input == 'm') {
            for (int i = 0; i < SIZE; i++) {
                cout << "\033[0mВведите \033[95m" << i << "\033[0m элемент массива: \033[91m";
                cin >> arr[i];
            }
        } else if (input == 'r') {
            for (int i = 0; i < SIZE; i++)
                arr[i] = (float(rand())/float(RAND_MAX)) * 6.9;
        } else { continue; }
        break;
    }

    // вывод содержимого
    printf("\n\033[0;1mМассив \033[1;34marr\033[0;1m:\033[0m\n\n");
    for (int i = 0; i < SIZE; i++)
        printf("\033[94marr[\033[0;91m%d\033[0;94m]\033[0m = %.3f\n", i, arr[i]);
}
