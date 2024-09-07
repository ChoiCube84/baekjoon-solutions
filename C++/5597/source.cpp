#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long int;
using ull = unsigned long long int;

using ld = long double;
using pll = pair<ll, ll>;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	bitset<30> submitted(0);

	for (ll i=0; i<28; i++) {
		ll temp;
		cin >> temp;
		
		submitted[temp-1] = 1;
	}

	for (ll i=0; i<30; i++) {
		if (!submitted[i]) {
			cout << i+1 << "\n";
		}
	}

	return 0;
}