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
	
	ll n;
	cin >> n;
	
	switch (n % 8) {
		case 1:
			cout << 1;
			break;
		case 2:
		case 0:
			cout << 2;
			break;
		case 3:
		case 7:
			cout << 3;
			break;
		case 4:
		case 6:
			cout << 4;
			break;
		case 5:
			cout << 5;
			break;
	}
	
	return 0;
}