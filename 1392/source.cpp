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
	
	ll N, Q;
	cin >> N >> Q;
	
	vector<ll> song(N * 100, 0);
	
	ll curr = 0;
	
	for (ll i=1; i<=N; i++) {
		ll time;
		cin >> time;
		
		for (ll j=curr; j<curr + time; j++) {
			song[j] = i;
		}
		
		curr += time;
	}
	
	while (Q--) {
		ll time;
		cin >> time;
		
		cout << song[time] << '\n';
	}
	
	return 0;
}