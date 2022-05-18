#include <iostream>
#include <time.h>

using namespace std;

int main(void) {
    srand(time(0));
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 10;
        cout << arr[i] << " ";
    }
    cout << endl;

    int pIndex = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == arr[i + 1]) {
            pIndex = i + 1;
            break;
        }
    }
    if (pIndex == 0) cout << "В массиве нет одинаковых соседних элементов";
    else for (int i = pIndex + 1; i < 10; i++) cout << arr[i] << " ";
    cout << endl;
}