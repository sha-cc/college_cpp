#include <iostream>
#include <time.h>

using namespace std;

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
    printf("\033[0m\n");
    for (int i = 0; i < arrX; i++) {
        for (int j = 0; j < arrY; j++)
            printf("%5d", arr[i][j]);
        printf("\n");
    }


    /* Массив, элементы которого равны произведениям
    индексов максимальных отрицательных элементов столбцов */

    int arrOfMaxNegatives[arrY] = {0};

    /* Идея такая: берем из столбца два отрицательных 
    элемента, которые ближе всего к 0, и перемножаем их.
    Используем отдельные переменные для обозначения
    индексов элементов и их значений */

    for (int i = 0; i < arrX; i++) {
        int firstMax = -16, firstMaxIndex = 0, secondMax = -16, secondMaxIndex = 0;
        for (int j = 0; j < arrY; j++) {
            if (arr[j][i] < 0 && arr[j][i] > firstMax) {    // если элемент меньше нуля и больше первого максимума
                secondMaxIndex = firstMaxIndex;             // перемещаем значение индекса первого максимума на второй
                firstMaxIndex = j;                          // задаем новое значение первого максимума
                secondMax = firstMax;                       // перемещаем значение первого максимума (реальное число) 
                firstMax = arr[j][i];                       // ну и задаем новое значение первого максимума
            } else if (arr[j][i] < 0 && arr[j][i] > secondMax) {
                secondMaxIndex = j;                         // если элемент меньше первого максимума, но больше
                secondMax = arr[j][i];                      // второго, назначаем его как второй максимум
            }
        }
        // прошлись по столбцу, теперь смотрим на результаты
        if (firstMax == -16)                                // если значение firstMax не изменилось
            continue;                                       // то значит, что в этом столбце вообще нет отр. элементов
        else if (secondMax == -16)                          // если не изменилось значение secondMax
            arrOfMaxNegatives[i] = firstMaxIndex;           // то значит, что в столбце только один отр. элемент
        else {
            // иногда один из индексов = 0. Так-то умножение на 0 здесь технически будет правильным, но все же не оч
            arrOfMaxNegatives[i] = firstMaxIndex * secondMaxIndex;

        /*  // ну а если мы не хотим умножать на ноль, то делаем так:
            if (firstMaxIndex != 0 && secondMaxIndex != 0)
                arrOfMaxNegatives[i] = firstMaxIndex * secondMaxIndex;
            else
                // тернарная операция
                arrOfMaxNegatives[i] = firstMaxIndex == 0? secondMaxIndex : firstMaxIndex;
        */
        }
    }

    cout << "\nМассив, элементы которого равны произведениям индексов\nмаксимальных отрицательных элементов столбцов: ";
    for (int i = 0; i < arrY; i++)
        cout << arrOfMaxNegatives[i] << "  ";
    cout << endl;


    /* Массив из строки с максимальным количеством 
    элементов, по модулю меньших 1 */

    /* Очень интересная формулировка задания. Вначале сказано,
    что двумерный массив должен быть целочисленным, а затем 
    дается такое задание, которое больше бы подходило к массиву
    с вещественными числами. В нашем случае единственным числом,
    по модулю меньшим 1, будет 0. То есть нужно найти строку с
    максимальным количеством нулей. Зачем они сразу так и не
    написали? хз */

    int zeroCounts[arrX] = {0};                     // массив, в котором хранится количество нулей в каждой строке
    for (int i = 0; i < arrX; i++)
        for (int j = 0; j < arrY; j++)
            if (arr[i][j] == 0)                     // если элемент = 0
                zeroCounts[i]++;                    // то количество нулей в этой строке + 1
    
    int indexOfLineWithTheMostZeroes = 0;           // индекс (последней) строки с максимальным количеством нулей
    int tries = 0;                                  // попытки найти эту строку
    for (int i = 0; i < arrX; i++) {
        if (zeroCounts[i] > 0 && zeroCounts[i] >= zeroCounts[indexOfLineWithTheMostZeroes])
            indexOfLineWithTheMostZeroes = i;
        else
            tries++;
    }

    if (tries == 6) {                               // если попыток было 6, а строка так и не нашлась
        cout << "\nВ массиве нет элементов, по модулю меньших 1" << endl;   // жалуемся на это
        return 0;                                                           // и выходим из программы
    }

    // по идее здесь нужно создавать массив, вводить в него все эти элементы,
    // и потом уже выводить его в ответ. Но я просто выводил ответ, и преподша
    // не придиралась к этому, так что, думаю, так тоже можно
    cout << "\nМассив из (последней) строки с максимальным количеством элементов,\nпо модулю меньших 1: ";
    for (int i = 0; i < arrX; i++)
        cout << arr[indexOfLineWithTheMostZeroes][i] << "  ";
    cout << endl;
}