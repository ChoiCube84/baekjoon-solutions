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
	
	ll n, m = 0;
	cin >> n;
	
	vector<ll> a(n);
	for (ll i=0; i<n; i++) {
		cin >> a[i];
		m += a[i];
	}
	
	sort(a.begin(), a.end());
	
	ll avg = m / n;
	ll rest = m - avg * n;
	
	ll result = 0;
	
	for (ll i=0; i<n; i++) {
		if (i < n-rest) {
			if (a[i] < avg) {
				result += avg - a[i];
			}
		}
		else if (a[i] < avg + 1) {
			result += avg + 1 - a[i];
		}
	}
	
	cout << result;
	
	return 0;
}