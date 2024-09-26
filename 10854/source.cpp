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

    ull N;
    cin >> N;

    auto factors = pollard_rho::factorize(N);

    ull result = 1;

    for (auto [factor, power] : factors) {
        result *= (power + 1);
    }

    cout << result;
    
    return 0;
}