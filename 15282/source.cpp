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
	
	ll n, m;
	cin >> n >> m;
	
	vector<ll> t(n);
	vector<ll> l(m);
	
	for (ll i=0; i<n; i++) {
		cin >> t[i];
	}
	
	for (ll i=0; i<m; i++) {
		cin >> l[i];
	}
	
	sort(t.begin(), t.end());
	sort(l.begin(), l.end());
	
	ll task_pointer = 0;
	ll interval_pointer = 0;
	
	ll result = 0;
	
	while (task_pointer < n && interval_pointer < m) {
		if (t[task_pointer] > l[interval_pointer]) {
			interval_pointer++;
		}
		else {
			result++;
			
			task_pointer++;
			interval_pointer++;
		}
	}
	
	cout << result;
	
	return 0;
}