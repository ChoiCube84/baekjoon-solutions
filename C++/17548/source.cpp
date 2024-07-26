#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string input;
    cin >> input;

    int eCount = 0;
    for (auto& c : input) {
        if (c == 'e') {
            eCount++;
        }
    }

    cout << 'h';
    for (int i=0; i<eCount*2; i++) {
        cout << 'e';
    }
    cout << 'y';

    return 0;
}