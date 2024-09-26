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

	ll p1, q1, p2, q2;
	cin >> p1 >> q1 >> p2 >> q2;

	cout << ((p1 * p2) % (q1 * q2) == 0);
	
	return 0;
}