# Лабораторная работа 15-16
![shield_license](https://img.shields.io/github/license/sha-cc/college_cpp)
![shield_language](https://img.shields.io/badge/language-C%2B%2B-blue)
## Задание 1
```cpp
#include <iostream>

using namespace std;

/* Функция, вычисляющая максимум двух целых чисел */

void maximum(int one, int two);

int main(void) {
    int one, two;
    cout << "First number: "; cin >> one;
    cout << "Second number: "; cin >> two;
    maximum(one, two);
}

void maximum(int one, int two) {
    if (one == two) cout << "Same numbers";
    else {
        int maximum = one > two? one: two;
        cout << "Maximum: " << maximum << endl;
    }
}
```

## Задание 2
```cpp
#include <iostream>

using namespace std;

/* Функция, вычисляющая максимум трех вещественных чисел */

void maximum(float one, float two, float three);

int main(void) {
    float one, two, three;
    cout << "First number: "; cin >> one;
    cout << "Second number: "; cin >> two;
    cout << "Third number: "; cin >> three;
    maximum(one, two, three);
}

void maximum(float one, float two, float three) {
    if (one == two && two == three) cout << "Same numbers" << endl;
    else {
        float maximum = (one > two)? ((one > three)? one : three) : ((two > three)? two : three);
        cout << "Maximum: " << maximum << endl;
    }
}
```


## Задание 3
```cpp
#include <iostream>

using namespace std;

/* Функция, вычисляющая сумму нечетных чисел в диапазоне от m до n */

void sum(int m, int n);

int main(void) {
    int m, n;
    cout << "m = "; cin >> m;
    cout << "n = "; cin >> n;
    sum(m, n);
}

void sum(int m, int n) {
    int sum = 0;
    for (int i = m; i < n; i++) if (i % 2 != 0) sum += i;
    cout << "Sum of odd numbers between " << m << " and " << n << " is " << sum << endl;
}
```


## Задание 4
```cpp
#include <iostream>

using namespace std;

/* Функция, выводящая цифры заданного числа в обратном порядке */

void reverse(int number);

int main(void) {
    int number;
    cout << "Number: "; cin >> number;
    reverse(number);
}

void reverse(int number) {
    cout << "Reversed: ";
    while (number != 0) {
        cout << number % 10;
        number /= 10;
    }
    cout << endl;
}
```


## Задание 5
```cpp
#include <iostream>

using namespace std;

/* Функция, вычисляющая сумму цифр заданного числа */

void sum(int number);

int main(void) {
    int number;
    cout << "Number: "; cin >> number;
    sum(number);
}

void sum(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    cout << "Sum of digits: " << sum << endl;
}
```


## Задание 6
```cpp
#include <iostream>

using namespace std;

/* Функция, выводящая числа в диапазоне от m до n, сумма цифр которых не превосходит 9 */

void discriminator9000(int m, int n);

int main(void) {
    int m, n;
    cout << "m = "; cin >> m;
    cout << "n = "; cin >> n;
    discriminator9000(m, n);
}

void discriminator9000(int m, int n) {
    for (int i = m; i < n; i++) {
        int temp = i, digiSum = 0; 
        while (temp != 0) {
            digiSum += temp % 10;
            temp /= 10;
        }
        if (digiSum <= 9) cout << i << " ";
    }
    cout << endl;
}
```


## Задание 7
```cpp
#include <iostream>

using namespace std;

/* Функция, вычисляющая произведение нечетных цифр заданного числа */

void thing(int number);

int main(void) {
    int number;
    cout << "Number: "; cin >> number;
    thing(number);
}

void thing(int number) {
    int product = 1;
    while (number != 0) {
        if (number % 10 % 2 != 0) product *= number % 10;
        number /= 10;
    }
    cout << "Sum of odd digits: " << product << endl;
}
```


## Задание 8
```cpp
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
```


## Задание 9
```cpp
#include <iostream>

using namespace std;

/* Функция, меняющая местами значения двух целых чисел */

int swap(int *one, int *two);

int main(void) {
    int one, two;
    cout << "one = "; cin >> one;
    cout << "two = "; cin >> two;
    swap(&one, &two);
    cout << "Now one = " << one << " and " << "two = " << two << endl;
}

int swap(int *one, int *two) {
    int tmp = *two;
    *two = *one;
    *one = tmp;
    return 0;
}
```


## Задание 10
```cpp
#include <iostream>

using namespace std;

/* Функция для вычисления координат точки через одну секунду */

void tic(int x, int y, int Vx, int Vy);

int main(void) {
    int x = 10, y = 15, Vx = 5, Vy = 10;
    cout << "x = " << x << ", y = " << y << endl;
    cout << "Speed in x direction = " << Vx << ", speed in y direction = " << Vy << endl;
    tic(x, y, Vx, Vy);
}

void tic(int x, int y, int Vx, int Vy) {
    x += Vx; y += Vy;
    cout << "In one second x will be = " << x << ", y will be = " << y << endl;    
}
```


## Задание 11
```cpp
#include <iostream>
#include <cmath>

using namespace std;

/* Функция, вычисляющая корни квадратного уравнения без использования операций ввода/вывода данных */

const char *root(float a, float b, float c, float *x1, float *x2);

int main(void) {
    float a, b, c, x1, x2;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;

    if (root(a, b, c, &x1, &x2) == "err_no_root") cout << "\nRoot not found" << endl;
    else if (x1 == x2) cout << "\nx = " << x1 << endl;
    else cout << "\nx1 = " << x1 << endl << "x2 = " << x2 << endl;
}

const char *root(float a, float b, float c, float *x1, float *x2) {
    float D = pow(b, 2) - 4 * a * c;
    if (D > 0) {
        *x1 = ((-b) + sqrt(D)) / (2 * a);
        *x2 = ((-b) - sqrt(D)) / (2 * a);
    }
    else if (D == 0) *x1 = *x2 = -(b / (2 * a));
    else if (D < 0) return "err_no_root";
    return 0;
}
```