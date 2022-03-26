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