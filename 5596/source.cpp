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
	
	ll a1, b1, c1, d1;
	ll a2, b2, c2, d2;
	
	cin >> a1 >> b1 >> c1 >> d1;
	cin >> a2 >> b2 >> c2 >> d2;
	
	cout << max(a1 + b1 + c1 + d1, a2 + b2 + c2 + d2);
	
	return 0;
}