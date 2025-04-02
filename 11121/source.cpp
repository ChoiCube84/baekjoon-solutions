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
	
	ll T;
	cin >> T;

	while (T--) {
		string a, b;
		cin >> a >> b;

		if (a == b) {
			cout << "OK";
		}
		else {
			cout << "ERROR";
		}
		
		cout << '\n';
	}
	
	return 0;
}