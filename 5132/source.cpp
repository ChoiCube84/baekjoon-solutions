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
	
	ll K;
	cin >> K;
	
	for (ll k=1; k<=K; k++) {
		ll n;
		cin >> n;
		
		vector<ll> v(n);
		vector<ll> dp(n, 0);
		
		for (ll i=0; i<n; i++) {
			cin >> v[i];
		}
		
		cout << "Data Set " << k << ":\n";
		
		dp[0] = v[0];
		if (n == 1) {
			cout << dp[0] << '\n' << '\n';
			continue;
		}
		
		dp[1] = v[1];
		if (n == 2) {
			cout << max(dp[0], dp[1]) << '\n' << '\n';
			continue;
		}
		
		dp[2] = dp[0] + v[2];
		if (n == 3) {
			cout << max(dp[1], dp[2]) << '\n' << '\n';
			continue;
		}
		
		for (ll i=3; i<n; i++) {
			dp[i] = max(dp[i-2], dp[i-3]) + v[i];
		}
		
		cout << max(dp[n-1], dp[n-2]) << '\n' << '\n';
	}
	
	return 0;
}