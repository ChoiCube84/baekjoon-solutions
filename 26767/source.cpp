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
	
	for (ll i=1; i<=N; i++) {
		if (i % 7 == 0) {
			if (i % 11 == 0) {
				cout << "Wiwat!" << '\n';
			}
			else {
				cout << "Hurra!" << '\n';
			}
		}
		else if (i % 11 == 0) {
			cout << "Super!" << '\n';
		}
		else {
			cout << i << '\n';
		}
	}
	
	return 0;
}