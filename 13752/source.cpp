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
	
	ll n;
	cin >> n;
	
	for (ll i=0; i<n; i++) {
		ll k;
		cin >> k;
		
		for (ll j=0; j<k; j++) {
			cout << '=';
		}
		
		cout << '\n';
	}
	
	return 0;
}