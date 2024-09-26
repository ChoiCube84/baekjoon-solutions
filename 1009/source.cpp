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
        int a, b;
        cin >> a >> b;

        a %= 10;

        int result = 1;
        for (int i=0; i<b; i++) {
            result = (result * a) % 10; 
        }

        cout << (result == 0 ? 10 : result) << '\n';
    }

    return 0;
}