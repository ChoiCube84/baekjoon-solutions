#include <bits/extc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string input;
    cin >> input;
    
    int result = 0;
    char curr = 'A';
    
    for (char c : input) {
        result += (min(abs(curr - c), 26 - abs(curr - c)));
        curr = c;
    }
    
    cout << result;
    
    return 0;
}
