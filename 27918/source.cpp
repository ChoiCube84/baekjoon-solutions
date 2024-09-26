#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int X = 0;
    int Y = 0;

    for (int i=0; i<N; i++) {
        string S;
        cin >> S;

        if (S == "D") {
            X++;
        }
        else {
            Y++;
        }

        if (abs(X - Y) >= 2) {
            cout << X << ":" << Y;
            return 0;
        }
    }

    cout << X << ":" << Y;

    return 0;
}