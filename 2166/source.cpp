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

	ll N, result = 0;
	vector<pll> dots;

	cin >> N;

	pll firstDot;
	cin >> firstDot.first >> firstDot.second;
	
	dots.emplace_back(firstDot);

	for (ll i=1; i<N; i++) {
		pll dot;
		cin >> dot.first >> dot.second;

		dots.emplace_back(dot);
	}

	dots.emplace_back(firstDot);

	for (ll i=0; i<N; i++) {
		result += dots[i].first * dots[i+1].second;
		result -= dots[i].second * dots[i+1].first;
	}

	cout << fixed;
	cout.precision(1);

	cout << static_cast<ld>(abs(result)) / 2;

	return 0;
}