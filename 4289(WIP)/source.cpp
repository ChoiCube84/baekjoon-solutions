#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

void simulate(ll n);
pll getWinLose(ll p1, ll p2, string m1, string m2);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;

	while (true) {
		cin >> n;

		if (n == 0) {
			break;
		}
		else {
			simulate(n);
		}
	}


	return 0;
}

void simulate(ll n) {
	ll k;
	cin >> k;

	vector<pll> winLose(n+1);

	for (ll i=0; i<k*n*(n-1)/2; i++) {
		ll p1, p2;
		string m1, m2;

		cin >> p1 >> m1 >> p2 >> m2;

		pll result = getWinLose(p1, p2, m1, m2);

		winLose[result.first].first++;
		winLose[result.second].second++;
	}

	for (ll i=1; i<=n; i++) {
		long double winRate = static_cast<long double>(winLose[i].first) / (winLose[i].first + winLose[i].second);

		cout << setprecision(3) << fixed << winRate << '\n';
	}

	cout << '\n';
}

pll getWinLose(ll p1, ll p2, string m1, string m2) {
	if (m1 == "rock") {
		if (m2 == "rock") {
			return make_pair(0, 0);
		}
		else if (m2 == "paper") {
			return make_pair(p2, p1);
		}
		else {
			return make_pair(p1, p2);
		}
	}
	else if (m1 == "paper") {
		if (m2 == "rock") {
			return make_pair(p1, p2);
		}
		else if (m2 == "paper") {
			return make_pair(0, 0);
		}
		else {
			return make_pair(p2, p1);
		}
	}
	else {
		if (m2 == "rock") {
			return make_pair(p2, p1);
		}
		else if (m2 == "paper") {
			return make_pair(p1, p2);
		}
		else {
			return make_pair(0, 0);
		}
	}
}