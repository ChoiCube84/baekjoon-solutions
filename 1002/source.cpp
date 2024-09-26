#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int i=0; i<T; i++) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if (r1 > r2) {
            swap(x1, x2);
            swap(y1, y2);
            swap(r1, r2);
        }

        int centerDistSquare = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int radSumSquare = (r1 + r2) * (r1 + r2);
        int radDiffSquare = (r2 - r1) * (r2 - r1);

        if (centerDistSquare > radSumSquare) {
            cout << 0 << "\n";
        }
        else if (centerDistSquare == radSumSquare) {
            cout << 1 << "\n";
        }
        else if (centerDistSquare < radDiffSquare) {
            cout << 0 << "\n";
        }
        else if (centerDistSquare == 0 && radDiffSquare == 0) {
            cout << -1 << "\n";
        }
        else if (centerDistSquare == radDiffSquare) {
            cout << 1 << "\n";
        }
        else {
            cout << 2 << "\n";
        }
    }

    return 0;
}