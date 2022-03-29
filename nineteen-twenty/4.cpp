#include <fstream>
#include <string>

using namespace std;

int main(void) {
    ifstream file1;
    ofstream file2;
    file1.open("file1.txt");
    file2.open("file2.txt");

    string line;
    while(getline(file1, line)) file2 << line << endl;

    file1.close();
    file2.close();
}