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
	
	ll N;
	cin >> N;
	
	ll total = 0;
	
	for (ll i=0; i<N; i++) {
		ll F;
		cin >> F;
		
		total += F;
	}
	
	if (total < T) {
		cout << "Padaeng_i Cry";
	}
	else {
		cout << "Padaeng_i Happy";
	}
	
	return 0;
}