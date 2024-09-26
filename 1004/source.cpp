#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;

struct Planet {
    int cx;
    int cy;
    int r;

    bool checkInside(int x, int y) {
        int distSquare = (cx - x) * (cx - x) + (cy - y) * (cy - y);

        if (distSquare < r * r) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int i=0; i<T; i++) {
        int x1, y1, x2, y2, result = 0;
        cin >> x1 >> y1 >> x2 >> y2;

        int n;
        cin >> n;

        vector<Planet> planets(n);

        for (int j=0; j<n; j++) {
            cin >> planets[j].cx >> planets[j].cy >> planets[j].r;
        }

        for (auto& planet : planets) {
            result += static_cast<int>(planet.checkInside(x1, y1) ^ planet.checkInside(x2, y2));
        }

        cout << result << "\n";
    }

    return 0;
}