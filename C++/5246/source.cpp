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

	ll T;
	cin >> T;

	while (T--) {
		ll N;
		cin >> N;

		vector<ll> count(9, 0);
		
		for (ll i=0; i<N; i++) {
			ll col, row;
			cin >> col >> row;

			count[row]++;
		}

		ll maximum = 0;
		
		for (ll i=1; i<=8; i++) {
			maximum = max(maximum, count[i]);
		}

		cout << maximum << '\n';
	}
	
	return 0;
}