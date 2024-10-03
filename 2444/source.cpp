#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;
using pll = pair<ll, ll>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N;
    cin >> N;
    
    if (N == 1) {
        cout << '*';
        return 0;
    }
    
    for (ll i=0; i<N; i++) {
        for (ll j=0; j<(N-1-i); j++) {
            cout << ' ';
        }
        for (ll j=0; j<2*i+1; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    
    for (ll i=N-2; i>=0; i--) {
        for (ll j=0; j<(N-1-i); j++) {
            cout << ' ';
        }
        for (ll j=0; j<2*i+1; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    
    return 0;
}