#include <bits/extc++.h>
#include "matrix.hpp"

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll T, N, D, mod = 1'000'000'007;
	cin >> T >> N >> D;

	Matrix<ll> combined(N, N, false, mod);
	Matrix<ll> rest(N, N, true, mod);

	for (ll i=0; i<T; i++) {
		ll M;
		cin >> M;

		Matrix<ll> curr(N, N, false, mod);

		for (ll j=0; j<M; j++) {
			ll a, b, c;
			cin >> a >> b >> c;

			a--;
			b--;

			curr[a][b] = c % mod;
		}

		if (D % T > i) {
			rest = rest * curr;
		}
		else {
			if (D % T == i) {
				combined = rest;
			}

			combined = combined * curr;
		}
	}

	cout << combined.power(D / T) * rest;

	return 0;
}