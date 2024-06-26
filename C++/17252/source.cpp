#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    if (N == 0) {
        cout << "NO";
        return 0;
    }
    
    while (N > 0) {
        if (N % 3 == 0) {
            N /= 3;
        }
        else if (N % 3 == 1) {
            N--;
        }
        else {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    
    return 0;
}