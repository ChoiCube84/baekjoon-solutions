#include <bits/extc++.h>
#include "custom_algorithms.hpp"

using namespace __gnu_pbds;
using namespace std;

using namespace custom_algorithms;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll n;
	
	while (true) {
		cin >> n;
		
		if (n == 0) {
			break;
		}
		else if (n == 1) {
			cout << 0 << '\n';
		}
		else {
			cout << euler_totient::Phi(n) << '\n';
		}
	}
	
	return 0;
}