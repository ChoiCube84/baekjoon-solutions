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
	
	ld w, h;
	cin >> w >> h;
	
	cout << fixed;
	cout.precision(15);
	
	cout << w + h - sqrtl(w * w + h * h);
	
	return 0;
}