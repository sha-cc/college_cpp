#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void getfile(string filename);

int main(void) {
    //getfile("in.txt");

    char input;
    while(1) {
        cout << "* Find the number of words in this text. (f)\n"
        "* Find the number of words beginning with the letter 'a' (or 'A'). (a)\n"
        "* Display all palindromic words (a palindrome is a word that reads\n"
        "  equally from the beginning and from the end.) (p)\n"
        "* Count the number of sentences in the text. (c)\n"
        "* Print the offered text in reverse order. (r)\n"
        "* Change the file to be processed. (s)"
        "\n\n>> ";
        input = getchar();

        switch (input) {
            case 'f': break;
            case 'a': break;
            case 'p': break;
            case 'c': break;
            case 'r': break;
            case 's': break;
            default: continue;
        }
    }
}

void getfile(string filename) {
    ifstream file;
    file.open(filename);
}