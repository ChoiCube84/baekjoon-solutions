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
	
	ll N, M;
	cin >> N >> M;
	
	vector<pll> costs(M);
	
	for (ll i=0; i<M; i++) {
		cin >> costs[i].first >> costs[i].second;
	}
	
	sort(costs.begin(), costs.end());
	
	ll total_fee = 0;
	ll people_left = N;
	
	for (ll i=0; i<M; i++) {
		if (costs[i].second < people_left) {
			total_fee += costs[i].first * costs[i].second;
			people_left -= costs[i].second;
		}
		else {
			total_fee += costs[i].first * people_left;
			break;
		}
	}
	
	cout << total_fee;
	
	return 0;
}