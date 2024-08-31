#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;
using ld = long double;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M;
    cin >> N >> M;
    
    if (M == 1 || M == 2) {
        cout << "NEWBIE!";
    }
    else if (M <= N) {
        cout << "OLDBIE!";
    }
    else {
        cout << "TLE!";
    }
    
    return 0;
}
