#include <iostream>

using namespace std;

/* Вычислить количество ненулевых разрядов, стоящих на четных местах в двоичной записи числа */

void wtf(int number);

int main(void) {
    int number;
    cout << "Number: "; cin >> number;
    wtf(number);
}

void wtf(int number) {
    static int counter = 0, result = 0;
    if (number > 0) {
        if (counter % 2 == 0)
            if (number % 2 != 0) 
                result++;
        number /= 2;
        counter++;
        wtf(number);
    } else cout << "Result = " << result << endl;
}