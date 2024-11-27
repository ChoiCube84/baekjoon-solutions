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
	
	ll X, Y;
	cin >> X >> Y;
	
	for (ll i=X; i<=Y; i+=60) {
		cout << "All positions change in year " << i << '\n';
	}
	
	return 0;
}