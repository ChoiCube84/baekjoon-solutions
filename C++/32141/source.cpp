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

	ll N, H;
	cin >> N >> H;

	vector<ll> d(N);
	for (ll i=0; i<N; i++) {
		cin >> d[i];
	}

	ll totalDamage = 0;
	ll cardCount = 0;

	for (ll i=0; i<N; i++) {
		totalDamage += d[i];
		cardCount++;
		
		if (totalDamage >= H) {
			break;
		}
	}

	if (totalDamage < H) {
		cout << -1;
	}
	else {
		cout << cardCount;
	}
	
	return 0;
}