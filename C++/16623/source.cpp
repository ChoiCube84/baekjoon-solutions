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
    
    ll n, m;
    cin >> n >> m;
    
    ll curr = 0;
    ll laps = 0;
    
    while (m--) {
        ll record;
        cin >> record;
        
        if (curr > record) {
            laps++;
        }
        
        curr = record;
    }
    
    cout << laps;
    
    return 0;
}
