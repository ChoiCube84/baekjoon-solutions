#include <bits/extc++.h>
#include "custom_algorithms.hpp"

using namespace __gnu_pbds;
using namespace std;

using namespace custom_algorithms;

using ll = long long int;
using ull = unsigned long long int;

using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ull a, N;
	cin >> a >> N;

	if (a == 1) {
		cout << -1;
		return 0;
	}	

	auto factors = pollard_rho::factorize(a);
	if (N / a < factors[0].first) {
		cout << -1;
	}
	else {
		cout << a * factors[0].first;
	}
	
	return 0;
}