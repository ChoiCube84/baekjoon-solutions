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

	ll n;
	cin >> n;

	vector<ll> s(n);
	for (ll i=0; i<n; i++) {
		cin >> s[i];
	}

	sort(s.begin(), s.end());

	ll minimum = LLONG_MAX;
	for (ll i=0; i<n/2; i++) {
		minimum = min(minimum, s[i] + s[n-i-1]);
	}

	cout << minimum;
	
	return 0;
}