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

	ll k;
	cin >> k;

	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll value = a * k + b;

	if (value == c * k + d) {
		cout << "YES" << ' ' << value;
	}
	else {
		cout << "NO";
	}
	
	return 0;
}