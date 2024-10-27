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
	
	string input;
	cin >> input;
	
	for (auto& c : input) {
		if (c == 'l') {
			c = 'L';
		}
		else {
			c = 'i';
		}
	}
	
	cout << input;
	
	return 0;
}