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
	
	ll n, d;
	cin >> n >> d;
	
	vector<ll> a(n);
	ll sum = 0;
	
	for (ll i=0; i<n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	
	for (ll i=0; i<n; i++) {
		cout << d * a[i] / sum << '\n';
	}
	
	return 0;
}