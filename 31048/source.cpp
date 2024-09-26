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

    int T;
    cin >> T;

    for (int t=0; t<T; t++) {
        int N;
        cin >> N;

        int result = 1;

        for (int i=1; i<=N; i++) {
            result *= i;
            result %= 10;
        }

        cout << result << '\n';
    }
    
    return 0;
}