#include <bits/extc++.h>
#include "custom_algorithms.hpp"

using namespace __gnu_pbds;
using namespace std;

using namespace custom_algorithms;

using ll = long long;
using ull = unsigned long long;

using ld = long double;
using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll n;
	
	while (cin >> n) {
		ll phi = euler_totient::Phi(n);
		
		if (phi == 1) {
			cout << 1 << '\n';
		}
		else {
			cout << phi / 2 << '\n';
		}
	}
	
	return 0;
}