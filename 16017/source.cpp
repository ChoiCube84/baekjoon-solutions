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
	
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	
	if (a > 7 && d > 7 && b == c) {
		cout << "ignore";
	}
	else {
		cout << "answer";
	}
	
	return 0;
}