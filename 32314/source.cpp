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
	
	ll a, w, v;
	cin >> a >> w >> v;
	
	if (w >= a * v) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	
	return 0;
}