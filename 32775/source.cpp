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
	
	ll S, F;
	cin >> S >> F;
	
	if (S > F) {
		cout << "flight";
	}
	else {
		cout << "high speed rail";
	}
	
	return 0;
}