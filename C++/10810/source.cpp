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

	vector<ll> basket(N, 0);

	while (M--) {
		ll i, j, k;
		cin >> i >> j >> k;

		i--;
		j--;

		for (ll curr=i; curr<=j; curr++) {
			basket[curr] = k;
		}
	}

	for (ll i=0; i<N; i++) {
		cout << basket[i] << ' ';
	}
	
	return 0;
}
