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
		ll minimum = LLONG_MAX;
		ll sum = 0;
		
		for (ll i=0; i<7; i++) {
			ll num;
			cin >> num;
			
			if (num % 2 == 0) {
				sum += num;
				minimum = min(minimum, num);
			}
		}
		
		cout << sum << ' ' << minimum << '\n';
	}
	
	return 0;
}