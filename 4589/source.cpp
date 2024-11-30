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
	
	ll N;
	cin >> N;
	
	cout << "Gnomes:" << '\n';
	
	while (N--) {
		ll a, b, c;
		cin >> a >> b >> c;
		
		if ((a < b && b < c) || (a > b && b > c)) {
			cout << "Ordered" << '\n';
		}
		else {
			cout << "Unordered" << '\n';
		}
	}
	
	return 0;
}