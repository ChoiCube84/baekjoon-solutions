#include <bits/extc++.h>
#include "custom_algorithms.hpp"

using namespace __gnu_pbds;
using namespace std;

using namespace custom_algorithms;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll a, b, n;
    cin >> a >> b >> n;

    cout << common::power(2147483648, n-1, 1000000007);

    return 0;
}