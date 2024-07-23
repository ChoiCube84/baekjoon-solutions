#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long double A1, P1, R1, P2;
    long double pi = 3.14159265358979;

    cin >> A1 >> P1 >> R1 >> P2;

    if (A1 / P1 > R1 * R1 * pi / P2) {
        cout << "Slice of pizza";
    }
    else {
        cout << "Whole pizza";
    }

    return 0;
}