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

	ll T;
	cin >> T;

	while (T--) {
		ll x, y;
		cin >> x >> y;

		cout << static_cast<ll>(sqrtl(4 * abs(x - y) - 3)) << '\n';
	}

	return 0;
}