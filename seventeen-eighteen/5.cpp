#include <iostream>

using namespace std;

int sequence(int A0, int A1, int n);

int main(void) {
    int A0, A1, n;
    cout << "A0 = "; cin >> A0;
    cout << "A1 = "; cin >> A1;
    cout << "n = "; cin >> n; 
    cout << "The " << n << "th term of the sequence is " << sequence(A0, A1, n) << endl;
}

// A(n) = -A(n-1) * A(n-2)

int sequence(int A0, int A1, int n) {

}