#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

ull fact(ull n, ull mod);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ull n;
    cin >> n;

    cout << fact(n, 1000000007);
    
    return 0;
}

ull fact(ull n, ull mod) {
    if (n <= 1) {
        return 1ULL;
    }
    else {
        return (n * fact(n - 1, mod)) % mod;
    }
}