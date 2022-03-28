#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void) {
    string line;

    ifstream file;
    file.open("in.txt");

    if (!file.is_open()) { 
        cerr << "\033[91mFailed to open file\033[0m" << endl;
        return 2;   // no such file or directory
    }

    while(getline(file, line)) cout << line << endl;

    file.close();
}