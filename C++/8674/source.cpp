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

    ull a, b;
    cin >> a >> b;

    if (a % 2 == 0 || b % 2 == 0) {
        cout << 0;
    }
    else {
        cout << min(a, b);
    }
    
    return 0;
}