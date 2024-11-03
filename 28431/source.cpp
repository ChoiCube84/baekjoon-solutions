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
	
	ll socks[10] = {0,};
	
	for (ll i=0; i<5; i++) {
		ll num;
		cin >> num;
		
		socks[num]++;
	}
	
	for (ll i=0; i<10; i++) {
		if (socks[i] % 2 == 1) {
			cout << i;
			break;
		}
	}
	
	return 0;
}