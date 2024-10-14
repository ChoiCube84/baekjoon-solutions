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
	
	ll p1, p2, p3, p4;
	cin >> p1 >> p2 >> p3 >> p4;
	
	ll x, y, r;
	cin >> x >> y >> r;
	
	if (x == p1) {
		cout << 1;
	}
	else if (x == p2) {
		cout << 2;
	}
	else if (x == p3) {
		cout << 3;
	}
	else if (x == p4) {
		cout << 4;
	}
	else {
		cout << 0;
	}
	
	return 0;
}