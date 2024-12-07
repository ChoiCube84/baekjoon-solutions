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
	
	ll a, b, c;
	cin >> a >> b >> c;
	
	if (a < b) {
		if (b < c) {
			cout << a << ' ' << b << ' ' << c;
		}
		else if (a < c) {
			cout << a << ' ' << c << ' ' << b;
		}
		else {
			cout << c << ' ' << a << ' ' << b;
		}
	}
	else {
		if (a < c) {
			cout << b << ' ' << a << ' ' << c;
		}
		else if (b < c) {
			cout << b << ' ' << c << ' ' << a;
		}
		else {
			cout << c << ' ' << b << ' ' << a;
		}
	}
	
	return 0;
}