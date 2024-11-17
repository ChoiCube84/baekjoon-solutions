#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ull = unsigned long long;

using ld = long double;
using pll = pair<ll, ll>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll AB;
	cin >> AB;
	
	ll A, B;
	
	if (AB < 100) {
		A = AB / 10;
		B = AB % 10;
	}
	else if (AB < 1000) {
		if (AB % 10 == 0) {
			A = AB / 100;
			B = 10;
		}
		else {
			A = 10;
			B = AB % 10;
		}
	}
	else {
		A = 10;
		B = 10;
	}
	
	cout << A + B;
	
	return 0;
}