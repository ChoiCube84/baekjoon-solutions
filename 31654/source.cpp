#include <iostream>

using namespace std;

int main(void) {
    int A, B, C;
    cin >> A >> B >> C;

    if (A + B == C) {
        cout << "correct!";
    }
    else {
        cout << "wrong!";
    }
    return 0;
}