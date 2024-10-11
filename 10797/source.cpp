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
	
	ll n, result = 0;
	cin >> n;
	
	for (ll i=0; i<5; i++) {
		ll input;
		cin >> input;
		
		if (input == n) {
			result++;
		}
	}
	
	cout << result;
	
	return 0;
}