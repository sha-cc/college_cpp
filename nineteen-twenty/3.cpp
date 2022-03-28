#include <time.h>
#include <fstream>

using namespace std;

int main(void) {
    srand(time(0));
    int n = 15, arr[n];
    for (int i = 0; i < n; i++) arr[i] = rand() % 511 - 256;
    ofstream file1;
    ofstream file2;
    file1.open("out.txt");
    file2.open("out.bin", ios_base::binary);

    for (int i = 0; i < n; i++) {
        file1 << arr[i];
        file2 << arr[i];
    }

    file1.close();
    file2.close();
}