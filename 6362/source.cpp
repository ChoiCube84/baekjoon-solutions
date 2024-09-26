#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

ll findDP(ll n, ll i, vector<vector<ll>>& dp);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<ll>> dp(251, vector<ll>(251, -1));

	while (true) {
		ll N;
		cin >> N;

		if (N == 0) {
			break;
		}
		else {
			cout << N << ' ' << findDP(N, 1, dp) << '\n';
		}
	}

	return 0;
}

ll findDP(ll n, ll i, vector<vector<ll>>& dp) {
	if (i > n) {
		return 0;
	}
	if (dp[n][i] != -1) {
		return dp[n][i];
	}

	ll sum;

	if (n % i == 0) {
		sum = 1;
	}
	else {
		sum = 0;
	}

	for (ll j=0; j<=(n/i); j++) {
		if (j % 2 == 0) {
			sum += findDP(n-(i*j), i+1, dp);
		}
	}

	dp[n][i] = sum;

	return sum;
}