#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

bool pairCollide(const pll& a, const pll& b);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll w, n;
	cin >> w >> n;

	vector<ll> A(n);
	for (ll i=0; i<n; i++) {
		cin >> A[i];
	}

	vector<pll> combinations(800001);

	for (ll i=0; i<800001; i++) {
		combinations[i].first = -1;
	}

	for (ll i=0; i<n; i++) {
		for (ll j=i+1; j<n; j++) {
			combinations[A[i] + A[j]] = make_pair(i, j);
		}
	}

	for (ll i=0; i<n; i++) {
		for (ll j=i+1; j<n; j++) {
			ll sum = A[i] + A[j];

			if (sum <= w && !(combinations[w - sum].first == -1) && !pairCollide(combinations[w - sum], make_pair(i, j))) {
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";

	return 0;
}

bool pairCollide(const pll& a, const pll& b) {
	if (a.first == b.first || a.first == b.second || a.second == b.first || a.second == b.second) {
		return true;
	}
	else {
		return false;
	}
}