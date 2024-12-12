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
	
	ll sum = 0;
	ll money = 0;
	
	while (true) {
		cin >> money;
		
		if (money == -1) {
			break;
		}
		else {
			sum += money;
		}
	}
	
	cout << sum;
	
	return 0;
}