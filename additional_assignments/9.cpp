#include <fstream>
#include <string>

using namespace std;

int main(void) {
    ifstream input; input.open("input.txt");
    ofstream output; output.open("output.txt");

    string line; int counter = 1;
    while(getline(input, line)) {
        if (counter == 3) {
            output << line << endl;
            break;
        }
        counter++;
    }
    input.close();
    output.close();
}