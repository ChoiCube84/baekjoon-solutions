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

    ull N, K;
    cin >> N >> K;

    ull sum = 0;

    for (int i=1; i<=N; i++) {
        sum *= pow(10, static_cast<int>(log10(i)) + 1);
        sum %= K;
        sum += i;
        sum %= K;
    }

    cout << sum;

    return 0;
}