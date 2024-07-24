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

    ull n;
    cin >> n;

    cout << "Is 162319020967 prime?: " << miller_rabin::isPrime(162319020967) << '\n';

    vector<pair<ull, ull>> result = pollard_rho::factorize(n);

    for (auto& [key, value] : result) {
        for (ull i=0; i<value; i++) {
            cout << key << '\n';
        }
    }

    return 0;
}