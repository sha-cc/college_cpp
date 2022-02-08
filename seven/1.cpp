#include <iostream>

using namespace std;

int main(void) {

    const int SIZE = 10;                // размер массива - константа

    float arr[SIZE];                    // создаем массив

    while (1) {
        char input;
        cout << "\n\033[94mИнициализация\033[0m: случайная\033[92m(r)\033[0m или вручную\033[92m(m)\033[0m? ";
        input = getchar();              // использовать getchar не обязательно, можно обойтись cin
        
        for (int i = 0; i < 45; i++) {  // эта непонятная конструкция просто выводит
            printf("-");                // линию из черточек на экран. От этого куска
        }                               // кода можно с легкостью избавиться, он тут
        printf("\n");                   // (почти) не нужен, только для визуала.

        if (input == 'm') {             // m - manual
            for (int i = 0; i < SIZE; i++) {
                printf("\033[0mВведите \033[95m%d\033[0m элемент массива: \033[91m", i);
                scanf("%f", &arr[i]);   // scanf тоже можно заменить на cin
                if (i == SIZE)
                    goto brk;           // break
            }
        } else if (input == 'r') {      // r - random
            for (int i = 0; i < SIZE; i++) {
                arr[i] = (float(rand())/float(RAND_MAX)) * 6.9; // я не знаю, как это работает. Но работает же!
                if (i == SIZE)
                    goto brk;           // break
            }
        } else { continue; }            // смысл цикла был только в том, что плохой ввод можно вот так игнорировать

        brk: break;                     // и да, я знаю, что goto не надо использовать. Cry about it lol
    }

    // вывод содержимого
    printf("\n\033[0;1mМассив \033[1;34marr\033[0;1m:\033[0m\n\n");
    for (int i = 0; i < SIZE; i++) {
        printf("\033[94marr[\033[0;91m%d\033[0;94m]\033[0m = %.3f\n", i, arr[i]);
    }
}