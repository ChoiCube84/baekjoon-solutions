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

    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;

    long double sum = static_cast<long double>(d1 + d2 + d3) / 2.0;

    long double a = sum - d3;
    long double b = sum - d2;
    long double c = sum - d1;

    if (a > 0 && b > 0 && c > 0) {
        cout << 1 << '\n';
        cout << setprecision(1) << fixed << a << " " << b << " " << c;
    }
    else {
        cout << -1;
    }
    
    return 0;
}