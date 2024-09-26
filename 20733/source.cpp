#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string input;
    cin >> input;
    
    int length = input.length();
    int segLength = length / 3;
    
    string A = input.substr(0, segLength);
    string B = input.substr(segLength, segLength);
    string C = input.substr(segLength + segLength, segLength);
    
    if (A != B && A != C) {
        cout << B;
    }
    else {
        cout << A;
    }
    
    return 0;
}
