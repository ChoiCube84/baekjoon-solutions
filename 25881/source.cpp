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

    int firstRate, afterRate;
    cin >> firstRate >> afterRate;

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int energy;
        cin >> energy;

        cout << energy << ' ' << firstRate * min(energy, 1000) + afterRate * max(0, energy - 1000) << '\n';
    }
    
    return 0;
}