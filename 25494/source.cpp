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
	
	ll T;
	cin >> T;
	
	while (T--) {
		ll a, b, c;
		cin >> a >> b >> c;
		
		ll result = 0;
		
		for (ll i=1; i<=a; i++) {
			for (ll j=1; j<=b; j++) {
				for (ll k=1; k<=c; k++) {
					ll xy = i % j;
					ll yz = j % k;
					ll zx = k % i;
					
					if (xy == yz && yz == zx) {
						result++;
					}
				}
			}
		}
		
		cout << result << '\n';
	}
	
	return 0;
}