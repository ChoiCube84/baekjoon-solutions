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

	ll N, M;
	cin >> N >> M;

	vector<ll> baskets(N+1, 0);

	for (ll i=1; i<=N; i++) {
		baskets[i] = i;
	}
	
	while (M--) {
		ll i, j;
		cin >> i >> j;

		while (i < j) {
			swap(baskets[i], baskets[j]);
			i++;
			j--;
		}
	}

	for (ll i=1; i<=N; i++) {
		cout << baskets[i] << ' ';
	}
	
	return 0;
}
