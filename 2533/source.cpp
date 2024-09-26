#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

void updateByDFS(const vector<vector<ll>>& graph, vector<vector<ll>>& dp, ll curr, ll parent);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N;
	cin >> N;

	vector<vector<ll>> graph(N+1);

	for (ll i=0; i<N-1; i++) {
		ll u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<vector<ll>> dp(2, vector<ll>(N+1, 0));
	updateByDFS(graph, dp, 1, 0);

	cout << min(dp[0][1], dp[1][1]);

	return 0;
}

void updateByDFS(const vector<vector<ll>>& graph, vector<vector<ll>>& dp, ll curr, ll parent) {
	if (graph[curr].size() == 1 && parent != 0) {
		dp[0][curr] = 0;
		dp[1][curr] = 1;

		return ;
	}

	for (auto& next : graph[curr]) {
		if (next == parent) {
			continue;
		}
		else {
			updateByDFS(graph, dp, next, curr);

			dp[0][curr] += dp[1][next];
			dp[1][curr] += dp[0][next];
		}
	}

	dp[1][curr]++;
}