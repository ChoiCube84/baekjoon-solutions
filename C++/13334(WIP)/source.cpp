#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;
using ld = long double;

struct cmp {
	bool operator()(const pll& a, const pll& b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}

		return a.first > b.first;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;

	std::priority_queue<pll, vector<pll>, cmp> pq;

	for (ll i=0; i<n; i++) {
		ll h, o;
		cin >> h >> o;

		if (h > o) {
			swap(h, o);
		}

		pq.push(make_pair(h, o));
	}

	ll d;
	cin >> d;

	ll maximum = 0;

	queue<pll> q;

	while (!pq.empty()) {
		auto curr = pq.top();
		pq.pop();

		if (q.empty()) {
			if (curr.second > curr.first + d) {
				continue;
			}
			else {
				q.push(curr);
				maximum = max<ll>(maximum, q.size());
			}
		}
		else {
			while (!q.empty() && curr.second > q.front().first + d) {
				q.pop();
			}

			if (q.empty() && curr.second > curr.first + d) {
				continue;
			}
			else {
				q.push(curr);
				maximum = max<ll>(maximum, q.size());
			}
		}
	}

	cout << maximum;

	return 0;
}