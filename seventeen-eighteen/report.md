# Лабораторная работа 17-18
![shield_license](https://img.shields.io/github/license/sha-cc/college_cpp)
![shield_language](https://img.shields.io/badge/language-C%2B%2B-blue)
## Задание 1
```cpp
#include <iostream>

using namespace std;

/* Вывести цифры числа, начиная со старшего разряда */

void reverse(int number);

int main(void) {
    int number;
    cout << "Number = "; cin >> number;
    reverse(number);
}

void reverse(int number) {
    if (number >= 10) 
        reverse(number / 10);
    int digit = number % 10;
    cout << digit << endl;
}
```

## Задание 2
```cpp
#include <iostream>

using namespace std;

/* Найти цифровой корень целого неотрицательного числа */

void digitalRoot(int a);

int main() {
    int number;
    cout << "Number: "; cin >> number;
    digitalRoot(number);
}

void digitalRoot(int number) {
    if (number < 10) cout << "Digital root: " << number << endl;
    else {
        int result = 0;
        while (number != 0) {
            result += number % 10;
            number /= 10;
        }
        digitalRoot(result);
    }
}
```


## Задание 3
### С рекурсией:
```cpp
#include <iostream>
 
using namespace std;

/* Найти максимальную цифру целого неотрицательного числа и её позицию в этом числе */

int maxDigit(long int number);

int main() {
    long int number;
    cout << "Number: "; cin >> number;
    maxDigit(number);
}

int maxDigit (long int number) {
    static int position = 0;            // позиция цифры для текущей итерации
    static int position_max = 0;        // позиция максимальной цифры
    static int max = 0;                 // максимальная цифра
    if (number == 0) {
        cout << "Max. digit: " << max << endl << "Position: " << position_max << endl;
        return 0;
    }
    else if (number % 10 > max) {
        max = number % 10;
        position_max = position;
    }   
    position++;
    number /= 10;
    maxDigit(number);
    return 0;
}
```

### Без рекурсии:
```cpp
#include <iostream>
#include <string>
 
using namespace std;

/* Найти максимальную цифру целого неотрицательного числа и её позицию в этом числе */

void maxDigit(long int number);

int main() {
    long int number;
    cout << "Number: "; cin >> number;
    maxDigit(number);
}

// явно не самый легкий способ сделать это

void maxDigit (long int number) {

    int length = to_string(number).length();        // количество цифр в числе
    int *arr = (int*) malloc(length * sizeof(int)); // каждая цифра числа - элемент массива
    int result = 0;                                 // самая большая цифра
    int position = 0;                               // ее позиция

    for (int i = 0; i < length; i++) {
        arr[i] = number % 10;
        number /= 10;
    }

    for (int i = length; i > 0; i--)
        if (arr[i] >= result) {
            result = arr[i];
            position = i;
        }

    cout << "Max. digit: " << result << endl;
    cout << "Position: " << position << endl;

    free(arr);
}
```


## Задание 4
```cpp
#include <iostream>

using namespace std;

/* Вычислить произведение нечетных цифр числа */

int productOfOdds(int number);
int product = 1;

int main(void) {
    int number;
    cout << "Number: "; cin >> number;
    productOfOdds(number);
}

int productOfOdds(int number) {
    if (number < 1) {
        cout << "Product of odd digits of the number: " << product << endl;
        return 0;
    } else {
        if ((number % 10) % 2 != 0) product *= (number % 10);
        number /= 10;
        productOfOdds(number);
    }
    return 0;
}
```


## Задание 5
### С рекурсией:
```cpp
#include <iostream>

using namespace std;

int sequence(int number, int first, int second);

int main(void) {
    int number, first, second;
    cout << "N = "; cin >> number;                  // номер члена, который нужно вычислить
    cout << "A0 = "; cin >> first;                  // нулевой член последовательности
    cout << "A1 = "; cin >> second;                 // первый член последовательности
    cout << sequence(number, first, second) << endl;
}

int sequence(int number, int first, int second) {
    switch (number) {
        case 0: return first;
        case 1: return second;
        default: return sequence(number - 1, first, second) * sequence(number - 2, first, second) * (-1);
    }
    return 0;
}
```


### Без рекурсии:
```cpp
#include <iostream>

using namespace std;

int sequence(int number, int first, int second);

int main(void) {
    int number, first, second;
    cout << "N = "; cin >> number;                  // номер члена, который нужно вычислить
    cout << "A0 = "; cin >> first;                  // нулевой член последовательности
    cout << "A1 = "; cin >> second;                 // первый член последовательности
    cout << sequence(number, first, second) << endl;
}

int sequence(int number, int first, int second) {
    int result, tmp1, tmp2;
    for (int i = 0; i < number - 1; i++) {
        if (i == 0) {
            result = first * second * (-1);
            tmp2 = result;
        } else if (i == 1) {
            result = second * tmp2 * (-1);
            tmp1 = result;
        } else {
            result = tmp1 * tmp2 * (-1);
            tmp2 = tmp1;
            tmp1 = result;
        }
    }
    return result;
}
```


## Задание 6
```cpp
#include <iostream>

using namespace std;

int sequence(int number);
int secondary(int number);

int main(void) {
    int number;
    cout << "N = "; cin >> number;
    cout << sequence(number) << endl;
}

int secondary(int number) {
    if (number == 0) return 1;
    else return secondary(number - 1) * (-1) + (number - 1) * sequence(number - 1);
}

int sequence(int number) {
    if (number == 0) return 1;
    else return 2 * secondary(number) - sequence(number - 1);
}
```


## Задание 7
```cpp
#include <iostream>

using namespace std;

/* Нахождение НОД с помощью алгоритма Евклида */

void nod(int a, int b);

int main(void) {
    int a, b;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    nod(a, b);
}

void nod(int a, int b) {
    if (a == b) 
        cout << "Greatest Common Divisor = " << a << endl;
    else if (a > b) {
        a = a - b;
        nod(a, b);
    } else {
        b = b - a;
        nod(a, b);
    }
}
```