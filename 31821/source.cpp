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
	
	ll N;
	cin >> N;
	
	vector<ll> prices(N+1);
	
	for (ll i=1; i<=N; i++) {
		cin >> prices[i];
	}
	
	ll M;
	cin >> M;
	
	ll total = 0;
	
	while (M--) {
		ll index;
		cin >> index;
		
		total += prices[index];
	}
	
	cout << total;
	
	return 0;
}