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
	
	vector<pll> locations1(W+1);
	vector<pll> locations2(W+1);
	
	locations1[0] = make_pair(1, 1);
	locations2[0] = make_pair(N, N);
	
	for (ll i=1; i<=W; i++) {
		cin >> locations1[i].first >> locations1[i].second;
		locations2[i] = locations1[i];
	}
	
	vector<vector<pair<ll, pll>>> dp(W+1, vector<pair<ll, pll>>(W+1, make_pair(10'000'000LL, make_pair<ll, ll>(0, 0))));
	
	dp[0][0].first = 0;
	dp[0][0].second = make_pair(0, 0);
	
	dp[1][0].first = dist(make_pair(1, 1), locations1[1]);
	dp[1][0].second = make_pair(0, 0);
	
	for (ll i=2; i<=W; i++) {
		dp[i][0].first = dp[i-1][0].first + dist(locations1[i-1], locations1[i]);
		dp[i][0].second = make_pair(i-1, 0);
	}
	
	dp[0][1].first = dist(make_pair(N, N), locations2[1]);
	dp[0][1].second = make_pair(0, 0);
	
	for (ll i=2; i<=W; i++) {
		dp[0][i].first = dp[0][i-1].first + dist(locations2[i-1], locations2[i]);
		dp[0][i].second = make_pair(0, i-1);
	}
	
	for (ll sum=3; sum<2 * W; sum++) {
		for (ll first=1; first<sum; first++) {
			ll second = sum - first;
			
			if (first > W || second > W) {
			    continue;
			}
			
			if (first > second) {
				if (first - second == 1) {
					for (ll start=0; start<=first-2; start++) {
						ll candidate = dp[start][second].first + dist(locations1[start], locations1[first]);
						
						if (dp[first][second].first > candidate) {
							dp[first][second].first = candidate;
							dp[first][second].second = make_pair(start, second);
						}
					}
				}
				else {
					dp[first][second].first = dp[first-1][second].first + dist(locations1[first-1], locations1[first]);
					dp[first][second].second = make_pair(first-1, second);
				}
			}
			else if (first < second) {
				if (second - first == 1) {
					for (ll start=0; start<=second-2; start++) {
						ll candidate = dp[first][start].first + dist(locations2[start], locations2[second]);
						
						if (dp[first][second].first > candidate) {
							dp[first][second].first = candidate;
							dp[first][second].second = make_pair(first, start);
						}
					}
				}
				else {
					dp[first][second].first = dp[first][second-1].first + dist(locations2[second-1], locations2[second]);
					dp[first][second].second = make_pair(first, second-1);
				}
			}
		}
	}
	
	ll minimum = LLONG_MAX;
	pll curr;
	
	for (ll i=0; i<W; i++) {
		if (minimum > dp[W][i].first) {
			minimum = dp[W][i].first;
			curr = make_pair(W, i);
		}
	}
	
	for (ll i=0; i<W; i++) {
		if (minimum > dp[i][W].first) {
			minimum = dp[i][W].first;
			curr = make_pair(i, W);
		}
	}
	
	stack<pll> s;
	s.push(curr);
	
	curr = dp[curr.first][curr.second].second;
	
	while (curr.first != 0 || curr.second != 0) {
		s.push(curr);
		curr = dp[curr.first][curr.second].second;
	}
	
	cout << minimum << '\n';
	
	ll first = 0;
	ll second = 0;
	
	while (!s.empty()) {
		auto curr = s.top();
		s.pop();
		
		if (first != curr.first) {
			cout << 1 << '\n';
		}
		else {
			cout << 2 << '\n';
		}
		
		first = curr.first;
		second = curr.second;
	}
	
	return 0;
}

ll dist(const pll& A, const pll& B) {
	return abs(A.first - B.first) + abs(A.second - B.second);
}