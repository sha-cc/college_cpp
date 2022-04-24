#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void getFile(string filename);
void wordCount();
void findA();
void findPalindromes();
void sentCount();
void reverseText();

int main(void) {
    
    char input;
    while(1) {
        cout << "* Find the number of words in this text. (f)\n"
        "* Find the number of words beginning with the letter 'a' (or 'A'). (a)\n"
        "* Display all palindromic words (p)\n"
        "* Count the number of sentences in the text. (c)\n"
        "* Print the offered text in reverse order. (r)\n"
        "\n\n>> ";
        input = getchar();

        switch (input) {
            case 'f': wordCount(); break;
            case 'a': findA(); break;
            case 'p': findPalindromes(); break;
            case 'c': sentCount(); break;
            case 'r': reverseText(); break;
            default: continue;
        }
        break;
    }
}

void wordCount() {
    ifstream file;
    file.open("in.txt");
    string line;
    int counter = 1;
    while(getline(file, line))
        for (int i=0; i<255; i++)
            if (line[i] == ' ')
                counter++;
    cout << "\nThis file has " << counter << " words" << endl;
}

void findA() {
    ifstream file;
    file.open("in.txt");
    string line;
    int counter = 1;
    while(getline(file, line))
        for (int i=0; i<255; i++)
            if (line[i] == ' ' && line[i + 1] == 'a' || line[i] == ' ' && line[i + 1] == 'A')
                counter++;
    cout << "\nThis file has " << counter << " words that start with a or A" << endl;
}

void findPalindromes() {
    ifstream file;
    file.open("in.txt");
    string line;
    int counter = 0;
    while(file >> line)
        if (line == string(line.rbegin(), line.rend()))
            counter++;
    cout << "\nThis file has " << counter << " palindroms" << endl;
}

void sentCount() {
    ifstream file;
    file.open("in.txt");
    string line;
    int counter = 0;
    while(getline(file, line))
        for (int i=0; i<255; i++)
            if (line[i] == '.')
                counter++;
    cout << "\nThis file has " << counter << " sentences" << endl;
}

void reverseText() {
    ifstream file;
    file.open("in.txt");
    string line;
    int counter = 0;
    while(getline(file, line)) {
        for (int i = line.length(); i >= 0; i--) {
            cout << line[i];
        }    
        cout << endl;    
    }
}