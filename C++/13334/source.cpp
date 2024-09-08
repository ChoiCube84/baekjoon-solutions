#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;
using ld = long double;

struct cmp {
	bool operator()(const pll& a, const pll& b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}

		return a.second < b.second;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;

	vector<pll> lines;

	for (ll i=0; i<n; i++) {
		ll h, o;
		cin >> h >> o;

		if (h > o) {
			swap(h, o);
		}

		lines.emplace_back(make_pair(h, o));
	}

	sort(lines.begin(), lines.end(), cmp());
	
	ll d;
	cin >> d;

	ll maximum = 0;

	std::priority_queue<int, vector<int>, greater<int>> pq;

	for (ll i=0; i<n; i++) {
		auto curr = lines[i];

		if (curr.second - curr.first <= d) {
			pq.push(curr.first);

			while (!pq.empty() && curr.second > pq.top() + d) {
				pq.pop();
			}
			
			maximum = max<ll>(maximum, pq.size());
		}
	}

	cout << maximum;

	return 0;
}