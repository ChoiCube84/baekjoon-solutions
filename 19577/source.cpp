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
	cin >> n;
	
	if (n == 1) {
		cout << 1;
		return 0;
	}
	else if (n == 2) {
		cout << 2;
		return 0;
	}
	
	for (ll i=1; i<=sqrtl(n)+1; i++) {
	    if (n % i == 0) {
	        if (euler_totient::Phi(i) == n / i) {
    			cout << i;
    			return 0;
    		}
			else if (euler_totient::Phi(n / i) == i) {
				cout << n / i;
				return 0;
			}
	    }
	}
	
	cout << -1;
	
	return 0;
}