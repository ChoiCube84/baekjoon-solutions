#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> dp(251, -1);
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	
	while (true) {
		int N;
		cin >> N;

		if (N == 0) {
			break;
		}
		else {
			if (dp[N] == -1) {
				for (int i=4; i<=N; i++) {
					if (dp[i] == -1) {
						for (int j=1; j<=i; j++) {
							// WIP
						}
					}
				}
			}
			cout << N << ' ' << dp[N] << '\n';
		}
	}
	
	return 0;
}