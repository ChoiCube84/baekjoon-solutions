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

	ll T;
	cin >> T;

	vector<ll> dp(10'000'001);

	ll MOD = 1'000'000'007;
	ll largestFound = 3;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 0;

	while (T--) {
		ll N;
		cin >> N;

		if (N > largestFound) {
			for (ll i=largestFound+1; i<=N; i++) {
				dp[i] = (i+1) * dp[i-1] - (i-2) * dp[i-2] - (i-5) * dp[i-3] + (i-3) * dp[i-4];
				dp[i] %= MOD;

				if (dp[i] < 0) {
					dp[i] += MOD;
				}
			}

			largestFound = N;
		}

		cout << dp[N] << '\n';
	}

	return 0;
}