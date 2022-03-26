#include <iostream>

using namespace std;

/* Функция, считающая, сколько раз ее вызвали */

int counter(void);

int main(void) {
    for (int i = 0; i < 5; i++) cout << "counter() was called " << counter() << " times" << endl;
}

int counter(void) {
    static int counter = 0;
    counter++;
    return counter;
}