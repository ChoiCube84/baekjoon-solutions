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
		ll x;
		cin >> x;
		
		cout << 2 * x - 1 << '\n';
	}
	
	return 0;
}