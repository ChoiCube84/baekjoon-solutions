#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll temp, b, a;
    for (ll i=0; i<23; i++) {
        cin >> temp;
    }
    cin >> b >> a;
    
    cout << a - b << '\n';
    cout << a * b << '\n';
    cout << a+b+1;
    
    return 0;
}