#include <bits/extc++.h>
#include "fraction.hpp"

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

	while (T--) {
		ll N, M;
		cin >> N >> M;

		vector<vector<ll>> A(M, vector<ll>(N, 0));
		vector<ll> V(M, 0);

		for (ll j=0; j<M; j++) {
			cin >> V[j];
			for (ll i=0; i<N; i++) {
				cin >> A[j][i];
			}
		}

		vector<Fraction<ll>> ate(N);

		for (ll j=0; j<M; j++) {
			for (ll i=0; i<N; i++) {
				ate[i] += Fraction(A[j][i], V[j]);
			}
		}

		Fraction<ll> minimum(M, 1);
		Fraction<ll> maximum(0, 1);

		for (ll i=0; i<N; i++) {
			if (ate[i] < minimum) {
				minimum = ate[i];
			}
			if (maximum < ate[i]) {
				maximum = ate[i];
			}
		}

		cout << maximum - minimum << '\n';
	}
	
	return 0;
}