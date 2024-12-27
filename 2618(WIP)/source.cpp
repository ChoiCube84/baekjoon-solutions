#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;
using pll = pair<ll, ll>;

ll dist(const pll& A, const pll& B);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll N, W;
	cin >> N >> W;
	
	vector<pll> locations(W);
	
	for (ll i=0; i<W; i++) {
		cin >> locations[i].first >> locations[i].second;
	}
	
	vector<vector<ll>> dp(W, vector<ll>(W, LLONG_MAX));
	
	for (ll i=0; i<W; i++) {
		// for (ll j=0; j<)
	}
	
	return 0;
}

ll dist(const pll& A, const pll& B) {
	return abs(A.first - B.first) + abs(A.second - B.second);
}