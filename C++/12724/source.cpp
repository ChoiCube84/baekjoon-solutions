#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll T;
	cin >> T;

	for (ll t=0; t<T; t++) {
		ll n;
		cin >> n;

		vector<ll> a(n);
		vector<ll> b(n);

		for (ll i=0; i<n; i++) {
			cin >> a[i];
		}

		for (ll i=0; i<n; i++) {
			cin >> b[i];
		}

		sort(a.begin(), a.end());
		sort(b.rbegin(), b.rend());

		ll sum = 0;

		for (ll i=0; i<n; i++) {
			sum += a[i] * b[i];
		}

		cout << "Case #" << t+1 << ": " << sum << '\n';
	}

	return 0;
}